// ConsoleApplication2.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"


#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <stdint.h>
#include <stdbool.h>
#include <conio.h>
#include <string.h>
#include <math.h>

#define WANTRANDS 28
#define WANTROWS 35

//��Ϸ����
//ǽ��ʼ��X����
#define WALL_X_BEGIN 0
//ǽ������X����
#define WALL_X_END WANTRANDS + 1

//ǽ��ʼ��Y����
#define WALL_Y_BEGIN 0
//ǽ������Y����
#define WALL_Y_END WANTROWS + 1

//�߽�����(��Ϸ����λ�ڱ߽���)
#define MAX_RANDS 29
#define MAX_ROWS 50

//����ģʽ���������ʳ����
#define limitFood_MAX 10
//����ģʽ�µ������Ϸʱ��,һ����
#define limitTime_MAX 60


typedef struct SnakeNode *SnakePoint;
//�ߵ����ݽṹ
typedef struct SnakeNode{
	//������Ϊx��Ϊ�У�������Ϊy��Ϊ��
	int pos_X;
	int pos_Y;
	//���ڹ���˫��ѭ�������ָ��
	SnakePoint next;
	SnakePoint previous;
}SnakeNode;

typedef struct FoodNode *FoodPoint;
//ʳ������ݽṹ
typedef struct FoodNode{
	//������Ϊx��Ϊ��
	int pos_X;
	//������Ϊy��Ϊ��
	int pos_Y;
	//���ڹ��쵥��ѭ�������ָ��
	FoodPoint next;
	//����ʳ�￪ʼʱ��
	clock_t food_CreateBeginTime;
}FoodNode;

//��ͷָ��
SnakePoint snakeHeadPoint = NULL;
//ʳ��ͷָ��
FoodPoint  foodHeadPoint = NULL;

//��ͣ��Ϸ,Ĭ��Ϊ��
bool Pause = false;

//����̨�������
COORD position;
//���ƾ��
HANDLE myHandle;

//��ͼԪ���������ֵ
enum { Wall, Empty, SnakeHead, SnakeBody, Food } MapElem;
//���������������ֵ
enum { Up, Down, Left, Right } Direct;

//��ͼmap[��][��]
int map[WANTRANDS + 2][WANTROWS + 2] = { Wall };

//��Ϸ�������
bool GameOver;
//�ߵĳ���
unsigned snakeLength;
unsigned Score;
//��Ϸ�ȼ�
int Level;
//ǰ���ٶ�
float Speed = 0.0;
//����ˢ��Ƶ������,����Ĭ��ֵ
int fps[11] = { 0 };


//Ҫ���λ�õ�����
int lastSnakeBody_X;
int lastSnakeBody_Y;
//�Ƿ�Ҫ�������Ĭ��Ϊ��
bool isErase = true;
//�Ե�ʳ����
bool isEatFood = false;
//������û�Ե�ʳ����м����������涨����GameOver
uint8_t dontEatCount = 0;
//���������
uint8_t Live = 0;

//��¼����ģʽ����ǰ��ͼ��ʳ�������
uint8_t limitFood_Count = 0;

//��ʱ���
//���ڼ�ʱ�ٶȵ�ʱ������
clock_t speed_BeginMarkTime;
clock_t speed_EndMarkTime;

//��¼Pause���������ĵ�ʱ��
clock_t pause_BeginMarkTime = 0;
clock_t pause_EndMarkTime = 0;
clock_t PauseWasteTime = 0;

//����ģʽ�µ���Ϸ��ʼʱ����
clock_t limitGame_BeginMarkTime = 0;
//����ģʽ�µĵ�ǰ��Ϸʱ��,Ϊint������Ϊ������30�롣
int8_t limit_CurrentTime = 0;

//��������
void gameInit();
void mapInit();
void prepareGame();
void creatFood();
bool isCreatFood(clock_t currentTime, float liveTime);
bool isCreatFood_FoodCount();

void gotoxy(int x, int y);
void keyDownControl(int key);
void move1(const SnakePoint tmpSnakeHeadPoint, int oldHead_X, int oldHead_Y);
void move2(const SnakePoint tmpSnakeHeadPoint, int oldHead_X, int oldHead_Y);
void move(const SnakePoint tmpSnakeHeadPoint);
void moved_procces();
void changSnake(int oldHeadPos_X, int oldHeadPos_Y);
void isGameOver();
void isTimeOver();
void gainScore();
int setLevel();
void setFps();
void raiseLevel();
void speedCaclate();

void putOne();
void prepareShow();
void showFood();
void showSnake();
void showWall();
void showInfoBorder();
void showGameOver();
void showInvariableInfo();
void showVariableInfo();
void showLimitCurrentTime();
void show();

void releseSnake();
void startGame();
void game();

void mainMenuAndGameEnter();
void normalGame();
void limitTimeGame();
void perfectGame();
void crazyGame();
void showHelp();
void gameEnter();


//��Ϸ��ʼ��
void gameInit()
{
	//�����Ϣ
	CONSOLE_CURSOR_INFO console_Info = { 1, false };
	//��ȡ����̨������
	myHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	//���ù���ڲ�
	SetConsoleCursorInfo(myHandle, &console_Info);
	//���ÿ���̨����
	SetConsoleTitleA("̰����");
	//���ÿ���̨�ı�����
	SetConsoleTextAttribute(myHandle, 0x7);

	/*
	ע��:������ô��ڵĴ�С������Ļ��������С�Ļ������ô��ڴ�Сʧ�ܡ�
	COORD ��X��Y��Ա����SHORT���������ǵ�������ֵ��Χ��0-32767��ʵ��
	������ˡ�X�ķ�Χ��80��32766��Y�ķ�Χ��25��32766�����������Χ��
	�����þ�ʧ����,rc����Ϊ��XYС1����Ȼ������ʧ����
	*/

	//����Ϊ���ô��ڴ�С���Լ�λ��
	//��ȡ��������Ϣ
	COORD size = { 100, 31 };
	SMALL_RECT rc = { 0, 0, 100 - 1, 31 - 1 };
	//���ô��ڻ�������С
	SetConsoleScreenBufferSize(myHandle, size);
	//���ô��ڴ�С
	SetConsoleWindowInfo(myHandle, 1, &rc);

	//�½�������ͷ�ڵ�
	snakeHeadPoint = (SnakePoint)malloc(sizeof(SnakeNode));
	//�½�ʳ������ͷ�ڵ�
	foodHeadPoint = (FoodPoint)malloc(sizeof(FoodNode));
}

//��ʼ����ͼ,��Ϸ�����ÿ�,�Լ����г�ʼ����ӡ����ʾ��ͼ����ɫ
void mapInit()
{
	for (int i = WALL_X_BEGIN + 1; i < WALL_X_END; ++i)
	{
		for (int j = WALL_Y_BEGIN + 1; j < WALL_Y_END; ++j)
		{
			map[i][j] = Empty;
			//��һ���ַ�Ϊ��λ��ӡ
			//putOne(i, j, map[i][j]);
		}
		//��һ��Ϊ��λ��ӡ
		gotoxy(i, 1);
		SetConsoleTextAttribute(myHandle, 0x20);
		printf("%70s", " ");
	}
}

//��Ϸ��ʼ֮ǰ��׼������
void prepareGame()
{
	//��ʼ����ͼ
	mapInit();
	//��ʼ�����з���Ϊ����
	Direct = Left;
	//��Ϸ����Ϊ��
	GameOver = false;
	//�ߵĳ�ʼ����
	snakeLength = 2;
	//��������
	Score = 0;
	//�ٶ�����
	Speed = 0.0;
	//�ȼ�����
	Level = 0;
	//���������
	Live = 3;
	//��ʼ������ģʽ��ʳ������
	limitFood_Count = 0;
	//��ʼ������ģʽ�µĵ�ǰ��Ϸʱ��
	limit_CurrentTime = 0;

	//��ʼ����ͷ���ֵ�����
	srand((unsigned)time(NULL));
	snakeHeadPoint->pos_X = (WALL_X_END - WALL_X_BEGIN) / 2 - 2 + rand() % 5;
	snakeHeadPoint->pos_Y = (WALL_Y_END - WALL_Y_BEGIN) / 2 - 4 + rand() % 9;
	//�ڵ�ͼ�ϱ�Ǵ�����Ϊ��ͷλ��
	map[snakeHeadPoint->pos_X][snakeHeadPoint->pos_Y] = SnakeHead;
	//���ɵ�һ������
	SnakePoint snakeBodyPoint = (SnakePoint)malloc(sizeof(SnakeNode));
	//�����ߵĳ�ʼ�˶���������ͷλ�õĺ�һ��λ�ü�һ������ڵ�
	snakeBodyPoint->pos_X = snakeHeadPoint->pos_X;
	snakeBodyPoint->pos_Y = snakeHeadPoint->pos_Y + 1;
	//�ڵ�ͼ�ϱ�Ǵ�����Ϊ����λ��
	map[snakeBodyPoint->pos_X][snakeBodyPoint->pos_Y] = SnakeBody;

	//����ͷ����������Ϊһ������Ϊ2����
	snakeHeadPoint->next = snakeBodyPoint;
	snakeHeadPoint->previous = snakeBodyPoint;
	snakeBodyPoint->next = snakeHeadPoint;
	snakeBodyPoint->previous = snakeHeadPoint;
	//����ʳ��
	creatFood();
}

//����ʳ��
void creatFood()
{
	//����ʳ�ʳ����������û�б�ռ�õ�����
	do{
		//�޶����ֵ�����ֻ����ǽ�ķ�Χ��
		foodHeadPoint->pos_X = rand() % (WALL_X_END - WALL_X_BEGIN - 1) + (WALL_X_BEGIN + 1);
		foodHeadPoint->pos_Y = rand() % (WALL_Y_END - WALL_Y_BEGIN - 1) + (WALL_Y_BEGIN + 1);
	} while (map[foodHeadPoint->pos_X][foodHeadPoint->pos_Y] != Empty);
	//�ڵ�ͼ����������б��
	map[foodHeadPoint->pos_X][foodHeadPoint->pos_Y] = Food;
	//��¼����ƻ����ʱ��
	foodHeadPoint->food_CreateBeginTime = clock();

	//ʳ������1
	++limitFood_Count;
}

//��λ����
void gotoxy(int x, int y)
{
	//������̨ϵͳ���꣬��map[��][��]�������Ӧ
	position.X = 2 * y;
	position.Y = x;
	SetConsoleCursorPosition(myHandle, position);
}

//��λ�����Լ����������ֵ�����Ԫ��
void putOne(int x, int y, int mapElem)
{
	switch (mapElem)
	{
		//Ϊ��
	case Empty:
		gotoxy(x, y);
		SetConsoleTextAttribute(myHandle, 0x20);
		printf("%2s", " "); break;
		//��ͷ�ڵ�
	case SnakeHead:
		gotoxy(x, y);
		SetConsoleTextAttribute(myHandle, 0x2C);
		printf("��"); break;
		//����
	case SnakeBody:
		gotoxy(x, y);
		SetConsoleTextAttribute(myHandle, 0x29);
		printf("��"); break;
		//ʳ��
	case Food:
		gotoxy(x, y);
		SetConsoleTextAttribute(myHandle, 0x2E);
		printf("��"); break;
		//ǽ
	case Wall:
		gotoxy(x, y);
		SetConsoleTextAttribute(myHandle, 0xD);
		printf("��"); break;
	}
}

//����ģʽ���õ��ƶ�����

//�ƶ�������ȷ�����������ƶ��㷨
void move(const SnakePoint tmpSnakeHeadPoint)
{
	int key = -1; //��Ϊ-1������Ҫ�������
	//�м�����,������
	while (_kbhit())
	{
		//ͬʱ���¶������ȡ���һ��
		key = _getch();
	}

	/*
	while(kbhit)
	keyDownControl(key);
	����������ַ�ʽ����ͬʱ�������з�����ͬһ����(����ͬ�Ͳ��෴)
	���෴����ʱ�س���GameOver�����磬����ǰ����ͬʱ�����󣬺Ͱ���
	�£���Ϊʱ��ܶ�����kbhit����1������ѭ����������������������Ƚ�
	������İ�������ôǰ�������Ϊ������Ȼ��������ҡ�ע��ԭ��������
	�������ǲ����в����ģ�������ǰһ�����裬����ʵ���������෴�����˶�
	����Ȼ��ͷ֮��Ϊ����������������ͨ����ײ��⣬�ж�ΪGameOver
	*/

	keyDownControl(key);
	//�����ͣ״̬���벻�ܽ���һ�г��˴�����ͣ�Ĵ���
	if (Pause)
	{
		return;
	}
	//�ȼ�¼��ͷ�ڵ����꣬��Ϊ֮��Ҫ���и���
	int oldHead_X = tmpSnakeHeadPoint->pos_X;
	int oldHead_Y = tmpSnakeHeadPoint->pos_Y;
	//����������ƶ�����
	switch (Direct){
		//�����ƶ�
	case Up:
		--tmpSnakeHeadPoint->pos_X; break;
		//�����ƶ�
	case Down:
		++tmpSnakeHeadPoint->pos_X; break;
		//�����ƶ�
	case Left:
		--tmpSnakeHeadPoint->pos_Y; break;
		//�����ƶ�
	case Right:
		++tmpSnakeHeadPoint->pos_Y; break;
	}

	//��ײ���
	isGameOver();
	if (GameOver)
		return;

	//�����߳��ȵ����ӣ��ж����ĸ��ƶ��㷨
	if (snakeLength <= 20)
	{
		move1(tmpSnakeHeadPoint, oldHead_X, oldHead_Y);
	}
	else{
		move2(tmpSnakeHeadPoint, oldHead_X, oldHead_Y);
	}

	//���Ϊ��ͷ
	map[tmpSnakeHeadPoint->pos_X][tmpSnakeHeadPoint->pos_Y] = SnakeHead;
}

void moved_procces()
{
	//�����ͣ״̬���벻�ܽ���һ�г��˴�����ͣ�Ĵ���
	if (Pause)
	{
		return;
	}

	//��������ʳ�����ʱ�䣬�ӵ�ͼ�Խ�����Ҫ�ƶ��Ĵ������Ե�ǰ��λʱ���ƶ�,��0.2��У�����
	float suitLiveFoodTime = sqrtf((float)(WANTROWS * WANTROWS + WANTRANDS * WANTRANDS))
		/ Speed * 10 + 0.1;
	if (isEatFood)
	{
		//������ʳ��
		creatFood();
		//�Ե�ʳ�ｫ��������
		dontEatCount = 0;
		//��ʳ������1
		--limitFood_Count;
	}

	else if (isCreatFood(clock(), suitLiveFoodTime))
	{
		//����ʳ�����
		map[foodHeadPoint->pos_X][foodHeadPoint->pos_Y] = Empty;
		putOne(foodHeadPoint->pos_X, foodHeadPoint->pos_Y,
			map[foodHeadPoint->pos_X][foodHeadPoint->pos_Y]);
		creatFood();

		++dontEatCount;
		//��������������Ϸ����
		if (dontEatCount > Live)
		{
			dontEatCount = 0;
			GameOver = true;
		}
	}
}

//����ģʽ�µ��ƶ�����
void moved_procces_Limit()
{
	//�����ͣ״̬���벻�ܽ���һ�г��˴�����ͣ�Ĵ���
	if (Pause)
	{
		return;
	}

	if (isEatFood)
	{
		//������ʳ��
		creatFood();
		//�Ե�ʳ�ｫ��������
		dontEatCount = 0;
		//��ʳ������1
		--limitFood_Count;
	}
	else if (isCreatFood_FoodCount())
	{
		creatFood();
	}
}

//���ݵ�ǰʳ������ȷ���Ƿ����ʳ��,��������ģʽ
bool isCreatFood_FoodCount()
{
	if (limitFood_Count < limitFood_MAX)
		return true;
	return false;
}

//���ݵ�ǰʱ���Լ�����ʱ���ж��Ƿ����ʳ��
bool isCreatFood(clock_t currentTime, float liveTime)
{
	//ʳ��ֻ����һ����ʱ��,��ȥ��ͣʱ�������ĵ�ʱ�䣬��������ͣʱʳ�����ʱ�䲻���������
	bool result = (((currentTime - foodHeadPoint->food_CreateBeginTime - PauseWasteTime) /
		(float)CLOCKS_PER_SEC) > liveTime);
	return result;
}

//��һ���ƶ��㷨��ÿ��ͨ�����ӽڵ��Լ�ɾ�����һ���ڵ�����ʵ���ƶ�
//����Ե�ʳ���򲻽���ɾ������
void move2(const SnakePoint tmpSnakeHeadPoint, int oldHead_X, int oldHead_Y)
{
	SnakePoint newSnakeBody = (SnakePoint)malloc(sizeof(SnakeNode));
	//����������
	newSnakeBody->pos_X = oldHead_X;
	newSnakeBody->pos_Y = oldHead_Y;

	//���������ߵ�˫��������
	tmpSnakeHeadPoint->next->previous = newSnakeBody;
	newSnakeBody->next = tmpSnakeHeadPoint->next;
	tmpSnakeHeadPoint->next = newSnakeBody;
	newSnakeBody->previous = tmpSnakeHeadPoint;
	//�������λ��Ϊ����
	map[newSnakeBody->pos_X][newSnakeBody->pos_Y] = SnakeBody;

	//���û�гԵ�ʳ��ɾ�����һ���ڵ�
	if (map[tmpSnakeHeadPoint->pos_X][tmpSnakeHeadPoint->pos_Y] != Food)
	{
		SnakePoint tmpLastSnake = tmpSnakeHeadPoint->previous;

		//��¼��Ҫ����������
		lastSnakeBody_X = tmpLastSnake->pos_X;
		lastSnakeBody_Y = tmpLastSnake->pos_Y;
		//���Ĵ�λ�ñ��
		map[tmpLastSnake->pos_X][tmpLastSnake->pos_Y] = Empty;

		//��ɾ���ڵ�֮ǰ�ı���ͷ�ڵ��ǰ�����Լ������ڶ����ڵ�ĺ��
		tmpSnakeHeadPoint->previous = tmpLastSnake->previous;
		tmpLastSnake->previous->next = tmpLastSnake->next;
		//�ͷŵ����һ���ڵ�
		free(tmpLastSnake);

		//����Ӧ�еı��
		isEatFood = false;
		//�������
		isErase = true;
	}
	//�Ե�ʳ�����Ӧ�еı��
	else{
		//�ߵĳ��ȼ�1
		++snakeLength;
		//�����в���
		isErase = false;
		//�Ե�ʳ��
		isEatFood = true;
	}
}

//�����ƶ������Ĳ���
void move1(const SnakePoint tmpSnakeHeadPoint, int oldHead_X, int oldHead_Y)
{
	//����Ե�ʳ�ͨ������ͷ֮�����һ���ڵ�ʵ���߽ڵ����ӣ������ڵ㲻������
	if (map[tmpSnakeHeadPoint->pos_X][tmpSnakeHeadPoint->pos_Y] == Food)
	{
		//�����½ڵ�
		SnakePoint newSnakeBody = (SnakePoint)malloc(sizeof(SnakeNode));
		//����������
		newSnakeBody->pos_X = oldHead_X;
		newSnakeBody->pos_Y = oldHead_Y;
		//���������ߵ�˫��������
		tmpSnakeHeadPoint->next->previous = newSnakeBody;
		newSnakeBody->next = tmpSnakeHeadPoint->next;
		tmpSnakeHeadPoint->next = newSnakeBody;
		newSnakeBody->previous = tmpSnakeHeadPoint;
		//�������λ��Ϊ����
		map[newSnakeBody->pos_X][newSnakeBody->pos_Y] = SnakeBody;

		//�ߵĳ��ȼ�1
		++snakeLength;
		//�����в���
		isErase = false;
		//�Ե�ʳ��
		isEatFood = true;
	}

	else
	{
		//û�Ե�ʳ�ﲻ���Ӻ�ɾ���ڵ㣬ͨ���ı���ڵ��������ʵ���ƶ�
		changSnake(oldHead_X, oldHead_Y);
		isEatFood = false;
	}
}

//���θ����������и��ڵ�����꣬������ͷ
void changSnake(int oldHeadPos_X, int oldHeadPos_Y)
{
	//����һ����ʱͷָ��
	SnakePoint lastSnakeBody = snakeHeadPoint->previous;
	/*�ڸı����һ������ڵ������ʱ�����ô����꽫��λ��
	���Ϊ�գ����Ϊ�ջ��ǲ����ģ���Ϊ���������֮ǰ��
	������ӡ�����ˡ���û������������һֱ��ʾ֮ǰ��ӡ��
	��ǣ�����Ҫ���½�����գ�ͨ����ӡ���������б��ʵ
	�֣���Ϊ�˽ڵ�Ҫ��ǰ�ƣ�ͨ����������ʵ��
	*/

	//��¼���һ���ڵ�����꣬��Ϊ����Ҫͨ��������������մ�λ�ñ��
	lastSnakeBody_X = lastSnakeBody->pos_X;
	lastSnakeBody_Y = lastSnakeBody->pos_Y;
	map[lastSnakeBody->pos_X][lastSnakeBody->pos_Y] = Empty;
	//��Ϊ�Ե�ʳ���һ�Σ���Ҫ���±�����״̬
	isErase = true;
	//���������յĻ��������β��˸
	//putOne(lastSnakeBody_X, lastSnakeBody_Y, map[lastSnakeBody_X][lastSnakeBody_Y]);

	//�����һ��������ǰ����������Ϊǰһ������,ֱ����һ������ڵ�(������ͷ)
	while (lastSnakeBody != snakeHeadPoint->next)
	{
		//β�ͽڵ�
		lastSnakeBody->pos_X = lastSnakeBody->previous->pos_X;
		lastSnakeBody->pos_Y = lastSnakeBody->previous->pos_Y;
		lastSnakeBody = lastSnakeBody->previous;
	}

	//�ı�ڶ����ڵ㼴��һ������ڵ������Ϊ����ͷ����
	snakeHeadPoint->next->pos_X = oldHeadPos_X;
	snakeHeadPoint->next->pos_Y = oldHeadPos_Y;
	//���Ϊ����
	map[oldHeadPos_X][oldHeadPos_Y] = SnakeBody;
}

//��������¼�
void keyDownControl(int key)
{
	//��ͣ/�����ͣע��(int)'P' = 80��ͻ
	if (key == 'p')
	{
		/*
		��Ϊ��ͣ�����Ƚ����⣬������ͣ������������Ϸ�Ļ������ٰ�һ�ν��
		��ǰ״̬�����Ե���ʼ���ʱ�䲻Ϊ��ʼֵʱ�ض���������ͣ�����������ж�
		��ʼʱ�����Ϊ���ʱ�̣�����ض������ٴΰ�����ͣ����״̬���Ա��ʱ��
		��ֵ���Ⱥ�˳�����Ҫ��Ҳ������һ����ʱ����������ֵ��ע��
		*/
		Pause = !Pause;
		if (pause_BeginMarkTime != 0)
		{
			pause_EndMarkTime = clock();
			PauseWasteTime = pause_EndMarkTime - pause_BeginMarkTime;
			//������ʱ�������³�ʼ��
			pause_BeginMarkTime = pause_EndMarkTime = 0;
		}
		else
			pause_BeginMarkTime = clock();
	}

	//��¼��ǰǰ������
	int currentDirect = Direct;
	//���ݰ�������ǰ������
	switch (key){
	case 'w':
	case 'W':
	case '8':
	case  72:
		if (currentDirect == Down)
			break;
		Direct = Up; break;
	case 's':
	case 'S':
	case '2':
	case  80:
		if (currentDirect == Up)
			break;
		Direct = Down; break;
	case 'a':
	case 'A':
	case '4':
	case  75:
		if (currentDirect == Right)
			break;
		Direct = Left; break;
	case 'd':
	case 'D':
	case '6':
	case  77:
		if (currentDirect == Left)
			break;
		Direct = Right; break;
	default:
		break;
	}
}

//��ײ���
void isGameOver()
{
	//����ͷ����ǽ������ʱ��Ϸ���Ϊ����
	if (snakeHeadPoint->pos_X == WALL_X_BEGIN ||
		snakeHeadPoint->pos_X == WALL_X_END ||
		snakeHeadPoint->pos_Y == WALL_Y_BEGIN ||
		snakeHeadPoint->pos_Y == WALL_Y_END ||
		map[snakeHeadPoint->pos_X][snakeHeadPoint->pos_Y] == SnakeBody)
		GameOver = true;
}

//����ģʽ���ж�ʱ���Ƿ�������
void isTimeOver()
{
	//�ж��Ƿ�Ϊ��һ��ʱ��У�飬ֻ����һ��
	static bool oneTimeCheck = false;

	//���Ϊ��ͣ��������ʱ����֮���ڼ�ȥ��ͣʱ������
	if (Pause)
	{
		//����ͣʱ��һ��ʱ��У����Ϊ����Ϊÿ��ͣһ�Σ�����ҪУ��һ��
		oneTimeCheck = false;
		return;
	}
	if (!oneTimeCheck)
	{
		//һ��ʱ��У��,ͨ����һ����ͣ������������ʼʱ����������ͣ�Լ�ʱ��Ӱ��
		limitGame_BeginMarkTime += PauseWasteTime;
		oneTimeCheck = true;
	}
	//һ��ʱ��У�����������ʱģʽ
	limit_CurrentTime = (int8_t)((clock() - limitGame_BeginMarkTime) / (float)CLOCKS_PER_SEC);

	//���ﵽ�޶�ʱ��ʱ����Ϸ����
	if (limit_CurrentTime > limitTime_MAX)
	{
		limit_CurrentTime = 0;
		GameOver = true;
	}
}

//���ֻ���,��㶨�ģ�Ҳ��������
void gainScore()
{
	//�����߳��ȵ����Ӹ�����Ӧ�ķ���
	if (snakeLength % 5 == 0)
	{
		switch (snakeLength / 5)
		{
		case 0:
			Score += 0; break;
		case 1:
		case 2:
		case 3:
			Score += 50; break;
		case 4:
		case 5:
		case 6:
			Score += 100; break;
		case 7:
		case 8:
			Score += 150; break;
		case 10:
		case 12:
			Score += 400; break;
		case 14:
		case 16:
			Score += 700; break;
		case 18:
			Score += 1100; break;
		case 20:
			Score += 1500; break;
		default:
			Score += 3000;
		}
	}
	//��������������ʱ��ÿ��һ��ʳ��ӵȼ�10������
	else{
		Score = Score + (Level + 1) * 10;
	}
}


void speedCaclate()
{
	//Ŀ��������ͳ��һ�����ڳ���ˢ�µĴ���
	static int count = 0;
	//����ʼ���������¿�ʼ����ʱ����¼��ǰʱ��Ϊ��ʼʱ��
	if (!count)
		speed_BeginMarkTime = clock();
	++count;
	speed_EndMarkTime = clock();
	if ((speed_EndMarkTime - speed_BeginMarkTime - setLevel()) >= 1.0 * CLOCKS_PER_SEC)
	{
		//Ϊ�˺ÿ����ڴ�����*10
		Speed = (float)count * 10.0;
		count = 0;
	}
}

//�����ȼ�����0~10��
void raiseLevel()
{
	//���߳���С��50ʱ��ÿ��10����һ������������ʮʱÿ��8����һ��
	if (snakeLength <= 50)
	{
		if ((snakeLength % 10 == 0) && (snakeLength / 10 != 0))
			++Level;
	}
	else if (snakeLength <= 90)
	{
		if (((snakeLength - 50) % 8 == 0) && ((snakeLength - 50) / 8 != 0))
			++Level;
	}

	else
	{

	}
}

//�����û���������ˢ��Ƶ�ʵĴ�С
void setFps()
{
	system("cls");
	int Fps = 0;
	gotoxy((MAX_RANDS - WALL_X_BEGIN) / 2 - 1, (MAX_ROWS - WALL_Y_BEGIN) / 2 - 4);
	SetConsoleTextAttribute(myHandle, 0xC);
	printf("������Ϸ�ٶȣ�(100 - 600)(Խ��Խ��)");
	gotoxy((MAX_RANDS - WALL_X_BEGIN) / 2, (MAX_ROWS - WALL_Y_BEGIN) / 2 - 7);
	printf("���ñȽϵ͵Ļ���������ѡ��Щ����ѡ���������Ӧ����");
	gotoxy((MAX_RANDS - WALL_X_BEGIN) / 2 + 1, (MAX_ROWS - WALL_Y_BEGIN) / 2 - 4);
	printf("Input:  ");
	scanf_s("%d", &Fps);
	//������뻺����
	fflush(stdin);
	//��ս���
	system("cls");

	if (Fps < 200)
	{
		int tmpFps[11] = { 110, 100, 90, 80, 70, 60, 50, 40, 30, 20, 15 };
		//���鿽��
		memcpy(fps, tmpFps, sizeof(int) * 11);
	}
	else if (Fps < 300)
	{
		int tmpFps[11] = { 200, 170, 150, 130, 110, 100, 80, 70, 60, 50, 20 };
		//���鿽��
		memcpy(fps, tmpFps, sizeof(int) * 11);
	}
	else if (Fps < 400)
	{
		int tmpFps[11] = { 300, 250, 200, 150, 120, 110, 100, 90, 80, 70, 40 };
		memcpy(fps, tmpFps, sizeof(int) * 11);
	}
	else if (Fps < 500)
	{
		int tmpFps[11] = { 400, 300, 250, 200, 150, 130, 120, 110, 90, 80, 60 };
		memcpy(fps, tmpFps, sizeof(int) * 11);
	}
	else if (Fps < 600)
	{
		int tmpFps[11] = { 500, 400, 300, 200, 180, 160, 140, 120, 110, 100, 70 };
		memcpy(fps, tmpFps, sizeof(int) * 11);
	}
	else if (Fps < 700)
	{
		int tmpFps[11] = { 600, 520, 450, 360, 300, 220, 180, 150, 130, 110, 90 };
		memcpy(fps, tmpFps, sizeof(int) * 11);
	}
	else
	{
		//Ĭ��
		int tmpFps[11] = { 110, 100, 90, 80, 70, 60, 50, 40, 30, 20, 10 };
		//���鿽��
		memcpy(fps, tmpFps, sizeof(int) * 11);
	}
}

//��Ϸ�ȼ�����,����ϵͳ˯��ʱ��
int setLevel()
{
	switch (Level)
	{
	case 0:
		return fps[0];
	case 1:
		return fps[1];
	case 2:
		return fps[2];
	case 3:
		return fps[3];
	case 4:
		return fps[4];
	case 5:
		return fps[5];
	case 6:
		return fps[6];
	case 7:
		return fps[7];
	case 8:
		return fps[8];
	case 9:
		return fps[9];
	case 10:
		return fps[9];
	default:
		return 0;
	}
}

//��ʾ��
void showSnake()
{
	/*
	��ÿ���ƶ�ֻ�ı��ֻ����ͷ�ڵ㣬�͵�һ������ڵ㣬����β�ڵ��ɲ����������д���
	����ÿ��ֻ��Ҫ���⼸���ڵ������ʾ����
	*/

	//��ʱͷ�ڵ㣬Ϊ�˲��ı�ͷ�ڵ��ָ��
	SnakePoint tmpSnakeHeadPoint = snakeHeadPoint;
	//����ʾͷ�ڵ�
	putOne(snakeHeadPoint->pos_X, snakeHeadPoint->pos_Y,
		map[snakeHeadPoint->pos_X][snakeHeadPoint->pos_Y]);
	//����ʾ��ͷ�����һ������ڵ�
	putOne(snakeHeadPoint->next->pos_X, snakeHeadPoint->next->pos_Y,
		map[snakeHeadPoint->next->pos_X][snakeHeadPoint->next->pos_Y]);


	//���ÿ�θ�����ʾ���нڵ㣬��ô�ƶ��ٶȻ������߳��ȵ����Ӷ�������
	//ԭ���Ǵ�ӡ��������Ҫ��һ����ʱ��
	/*
	//Ȼ��������ʾ�����ڵ�
	while(tmpSnakeHeadPoint->next != snakeHeadPoint)
	{
	putOne(tmpSnakeHeadPoint->next->pos_X, tmpSnakeHeadPoint->next->pos_Y,
	map[tmpSnakeHeadPoint->next->pos_X][tmpSnakeHeadPoint->next->pos_Y]);
	tmpSnakeHeadPoint = tmpSnakeHeadPoint->next;
	}
	*/
}

//ÿ���ƶ��󣬲�����ͼ���Ѳ�������ڵ�ı��
void eraseSnakeBody()
{
	putOne(lastSnakeBody_X, lastSnakeBody_Y, map[lastSnakeBody_X][lastSnakeBody_Y]);
}

//��ʾʳ��
void showFood()
{
	static unsigned downCount = 6;
	//ʵ����˸Ч��,�������Ҫ��˸�Ļ���ȥ�������伴��
	putOne(foodHeadPoint->pos_X, foodHeadPoint->pos_Y,
		map[foodHeadPoint->pos_X][foodHeadPoint->pos_Y]);

	for (int i = 0; i < downCount; ++i)
		putOne(foodHeadPoint->pos_X, foodHeadPoint->pos_Y, Empty);
	putOne(foodHeadPoint->pos_X, foodHeadPoint->pos_Y,
		map[foodHeadPoint->pos_X][foodHeadPoint->pos_Y]);
}

//��ʾǽ
void showWall()
{
	//��ʾ��������ǽ
	for (int j = WALL_Y_BEGIN; j <= WALL_Y_END; ++j)
	{
		putOne(WALL_X_BEGIN, j, map[WALL_X_BEGIN][j]);
		putOne(WALL_X_END, j, map[WALL_X_END][j]);
	}
	//��ʾ��������ǽ
	for (int i = WALL_X_BEGIN; i <= WALL_X_END; ++i)
	{
		putOne(i, WALL_Y_BEGIN, map[i][WALL_Y_BEGIN]);
		putOne(i, WALL_Y_END, map[i][WALL_Y_END]);
	}

}

//��ʾ��Ϸ������Ϣ
void showGameOver()
{
	for (int i = WALL_X_BEGIN + 1; i < WALL_X_END; ++i)
		for (int j = WALL_Y_BEGIN + 1; j < WALL_Y_END; ++j)
			putOne(i, j, Wall);
	gotoxy((WALL_X_END - WALL_X_BEGIN) / 2 - 1, (WALL_Y_END - WALL_Y_BEGIN) / 2 - 4);
	SetConsoleTextAttribute(myHandle, 0xC);
	printf("Game Over!");
	gotoxy((WALL_X_END - WALL_X_BEGIN) / 2 + 1, (WALL_Y_END - WALL_Y_BEGIN) / 2 - 5);
	printf("���¿�ʼ��(Y/N)Y");

	//������뻺����
	while (_kbhit())
		_getch();
}

//��ʾ��Ϣ��
void showInfoBorder()
{
	//��һ����
	//��ʾ���±߽�
	for (int j = WALL_Y_END + 2; j <= MAX_ROWS - 2; ++j)
	{
		putOne(WALL_X_BEGIN + 2, j, Wall);
		putOne(WALL_X_BEGIN + 2 + 5, j, Wall);
	}
	//��ʾ���ұ߽�
	for (int i = WALL_X_BEGIN + 2; i <= WALL_X_BEGIN + 2 + 5; ++i)
	{
		putOne(i, WALL_Y_END + 2, Wall);
		putOne(i, MAX_ROWS - 2, Wall);
	}

	//�ڶ�����
	//��ʾ���±߽�
	for (int j = WALL_Y_END + 2; j <= MAX_ROWS - 2; ++j)
	{
		putOne(WALL_X_BEGIN + 2 * 2 + 5, j, Wall);
		putOne(WALL_X_BEGIN + 2 * 2 + 5 * 2, j, Wall);
	}
	//��ʾ���ұ߽�D
	for (int i = WALL_X_BEGIN + 2 * 2 + 5; i <= WALL_X_BEGIN + 2 * 2 + 5 * 2; ++i)
	{
		putOne(i, WALL_Y_END + 2, Wall);
		putOne(i, MAX_ROWS - 2, Wall);
	}

	//��������
	//��ʾ���±߽�
	for (int j = WALL_Y_END + 2; j <= MAX_ROWS - 2; ++j)
	{
		putOne(WALL_X_BEGIN + 2 * 3 + 5 * 2, j, Wall);
		putOne(WALL_X_BEGIN + 2 * 3 + 5 * 3, j, Wall);
	}
	//��ʾ���ұ߽�
	for (int i = WALL_X_BEGIN + 2 * 3 + 5 * 2; i <= WALL_X_BEGIN + 2 * 3 + 5 * 3; ++i)
	{
		putOne(i, WALL_Y_END + 2, Wall);
		putOne(i, MAX_ROWS - 2, Wall);
	}

	//���ĸ���
	//��ʾ���±߽�
	for (int j = WALL_Y_END + 2; j <= MAX_ROWS - 2; ++j)
	{
		putOne(WALL_X_BEGIN + 2 * 4 + 5 * 3, j, Wall);
		putOne(WALL_X_BEGIN + 2 * 4 + 5 * 4, j, Wall);
	}
	//��ʾ���ұ߽�D
	for (int i = WALL_X_BEGIN + 2 * 4 + 5 * 3; i <= WALL_X_BEGIN + 2 * 4 + 5 * 4; ++i)
	{
		putOne(i, WALL_Y_END + 2, Wall);
		putOne(i, MAX_ROWS - 2, Wall);
	}
}

//��ʾʱ�̸ı����Ϣ
void showVariableInfo()
{
	//��ʾ������Ϣ
	gotoxy(WALL_X_BEGIN + 2 + 2, WALL_Y_END + 2 + 2);
	SetConsoleTextAttribute(myHandle, 0xE);
	printf("SCORE: %d", Score);
	gotoxy(WALL_X_BEGIN + 2 + 4, WALL_Y_END + 2 + 2);
	printf("SPEED: %7.3f", Speed);

	//��ʾ�ߵĳ���
	gotoxy(WALL_X_BEGIN + 2 * 2 + 5 + 1, WALL_Y_END + 2 + 2);
	SetConsoleTextAttribute(myHandle, 0xE);
	printf("LENGTH: %d", snakeLength);
	//��ʾ����ÿ�Ե�ʳ��ļ���
	gotoxy(WALL_X_BEGIN + 2 * 2 + 5 + 2, WALL_Y_END + 2 + 2);
	printf("��������: %d", dontEatCount);
	//��ʾ�ȼ�
	gotoxy(WALL_X_BEGIN + 2 * 2 + 5 + 3, WALL_Y_END + 2 + 2);
	printf("Level: %d", Level);
	gotoxy(WALL_X_BEGIN + 2 * 2 + 5 + 4, WALL_Y_END + 2 + 2);
	printf("FPS: %d  ", fps[Level]);
}

//��ʾ����ģʽ��ǰ��Ϸʱ��
void showLimitCurrentTime()
{
	gotoxy(WALL_X_BEGIN + 2 + 3, WALL_Y_END + 2 + 2);
	SetConsoleTextAttribute(myHandle, 0xE);
	printf("Time: %d", limit_CurrentTime);
}

void showInvariableInfo()
{
	//��ʾ������Ϣ
	gotoxy(WALL_X_BEGIN + 2 * 3 + 5 * 2 + 1, WALL_Y_END + 2 + 1);
	SetConsoleTextAttribute(myHandle, 0xA);
	printf("���ƣ�");
	printf("����: ��/W/8");
	gotoxy(WALL_X_BEGIN + 2 * 3 + 5 * 2 + 2, WALL_Y_END + 2 + 2);
	printf("����: ��/s/2");
	gotoxy(WALL_X_BEGIN + 2 * 3 + 5 * 2 + 3, WALL_Y_END + 2 + 2);
	printf("����: ��/A/4");
	gotoxy(WALL_X_BEGIN + 2 * 3 + 5 * 2 + 4, WALL_Y_END + 2 + 1);
	printf("����: ��/D/6 ��ͣP");

	//��ʾ������Ϣ
	gotoxy(WALL_X_BEGIN + 2 * 4 + 5 * 3 + 1, WALL_Y_END + 2 + 1);
	SetConsoleTextAttribute(myHandle, 0xC);
	printf("˵����������������");
	gotoxy(WALL_X_BEGIN + 2 * 4 + 5 * 3 + 2, WALL_Y_END + 2 + 2);
	printf("%d GameOver !", Live);
	gotoxy(WALL_X_BEGIN + 2 * 4 + 5 * 3 + 3, WALL_Y_END + 2 + 2);
	SetConsoleTextAttribute(myHandle, 0xA);
	printf("BY : WOA");
	gotoxy(WALL_X_BEGIN + 2 * 4 + 5 * 3 + 4, WALL_Y_END + 2 + 2);
	printf("Version : 1.1");
}

//ֻ��ÿ��������Ϸʱ������ʾ����
void prepareShow()
{
	showWall();
	showInfoBorder();
	showInvariableInfo();
}

void show()
{
	showSnake();
	//������ʾ֮���ٽ��в��������Ա�֤��β����˸
	if (isErase && !Pause)
		eraseSnakeBody();
	showFood();
	showVariableInfo();
}

//ע�⣬����Ϊ����ɾ�������Ҫ����ɾ��һ���ڵ�Ĳ����Ļ��벻Ҫ�ο��˷���
void releseSnake()
{
	SnakePoint tmpSnakeLast = snakeHeadPoint->previous;
	while (tmpSnakeLast != snakeHeadPoint)
	{
		//��¼�˽ڵ�
		SnakePoint tmpSnakeBody = tmpSnakeLast;
		//��¼�˽ڵ��ǰ��������ǰ�ƣ���û�н�������ָ�����
		tmpSnakeLast = tmpSnakeLast->previous;
		//�ͷŵ�ǰ�ڵ�
		free(tmpSnakeBody);
	}
	//��ʼ����ͷָ��
	snakeHeadPoint->previous = snakeHeadPoint->next = NULL;
}

//��ʼ��Ϸ
void startGame()
{
	do{
		show();
		Sleep(setLevel());
		move(snakeHeadPoint);
		moved_procces();
		speedCaclate();
		if (isEatFood && !Pause)
		{
			gainScore();
			raiseLevel();
		}

		if (GameOver)
			showGameOver();
	} while (!GameOver);
}
void gameEnter(int press)
{
	switch (press)
	{
	case 1:
		normalGame();
		//�˳��󷵻����˵�
		break;
	case 2:
		limitTimeGame();
		break;
	case 3:
		perfectGame();
		break;
	case 4:
		crazyGame();
		break;
	case 5:
		//��ʾһ�ΰ�����Ϣ��֮�����ѭ������Q�˳�
		showHelp();
		while (_getch() != 'Q');
		//�˳������·������˵�
		break;
	case 6:
		//�˳���Ϸ
		exit(0); break;
	}
}
//��ʾ���˵��Ĺ���ѡ��
void mainMenuAndGameEnter()
{
	system("cls");
	//������뻺��
	fflush(stdin);
	//��ѡ���ѡ������ֵ
	static int press = 1;
	//��¼�Ƿ���ȷ�ϼ�
	bool enterGame = false;
	//���˵�
	gotoxy((MAX_RANDS - WALL_X_BEGIN) / 2 - 6, (MAX_ROWS - WALL_Y_BEGIN) / 2 - 4);
	SetConsoleTextAttribute(myHandle, 0xE);
	printf("*   MENU   *");
	gotoxy((MAX_RANDS - WALL_X_BEGIN) / 2 - 4, (MAX_ROWS - WALL_Y_BEGIN) / 2 - 3);
	printf(" ����ģʽ");
	gotoxy((MAX_RANDS - WALL_X_BEGIN) / 2 - 2, (MAX_ROWS - WALL_Y_BEGIN) / 2 - 3);
	printf(" ��ʱģʽ");
	gotoxy((MAX_RANDS - WALL_X_BEGIN) / 2 - 0, (MAX_ROWS - WALL_Y_BEGIN) / 2 - 3);
	printf(" ����ģʽ");
	gotoxy((MAX_RANDS - WALL_X_BEGIN) / 2 + 2, (MAX_ROWS - WALL_Y_BEGIN) / 2 - 3);
	printf(" ����ģʽ");
	gotoxy((MAX_RANDS - WALL_X_BEGIN) / 2 + 4, (MAX_ROWS - WALL_Y_BEGIN) / 2 - 3);
	printf(" ��Ϸ����");
	gotoxy((MAX_RANDS - WALL_X_BEGIN) / 2 + 6, (MAX_ROWS - WALL_Y_BEGIN) / 2 - 3);
	printf(" �˳���Ϸ");

	//�Ƚ��е�һ����ʾ,����û�а��¼�ʱ����ʾ��ǰѡ�֮�󲢽��������Ƿ��¼��ĳ���δ���
	switch (press)
	{
	case 1:
		SetConsoleTextAttribute(myHandle, 0xC);
		gotoxy((MAX_RANDS - WALL_X_BEGIN) / 2 - 4, (MAX_ROWS - WALL_Y_BEGIN) / 2 - 3);
		printf("*����ģʽ");
		break;
	case 2:
		SetConsoleTextAttribute(myHandle, 0xC);
		gotoxy((MAX_RANDS - WALL_X_BEGIN) / 2 - 2, (MAX_ROWS - WALL_Y_BEGIN) / 2 - 3);
		printf("*��ʱģʽ");
		break;
	case 3:
		SetConsoleTextAttribute(myHandle, 0xC);
		gotoxy((MAX_RANDS - WALL_X_BEGIN) / 2 - 0, (MAX_ROWS - WALL_Y_BEGIN) / 2 - 3);
		printf("*����ģʽ");
		break;
	case 4:
		SetConsoleTextAttribute(myHandle, 0xC);
		gotoxy((MAX_RANDS - WALL_X_BEGIN) / 2 + 2, (MAX_ROWS - WALL_Y_BEGIN) / 2 - 3);
		printf("*����ģʽ");
		break;
	case 5:
		SetConsoleTextAttribute(myHandle, 0xC);
		gotoxy((MAX_RANDS - WALL_X_BEGIN) / 2 + 4, (MAX_ROWS - WALL_Y_BEGIN) / 2 - 3);
		printf("*��Ϸ����");
		break;
	case 6:
		SetConsoleTextAttribute(myHandle, 0xC);
		gotoxy((MAX_RANDS - WALL_X_BEGIN) / 2 + 6, (MAX_ROWS - WALL_Y_BEGIN) / 2 - 3);
		printf("*�˳���Ϸ");
		break;
	default:
		break;
	}


	do{
		//��û������ʱ��Ĭ��Ϊ-1��������,pressΪ1~6����6����ͬ�Ĺ���ѡ��
		int key = -1;
		//��¼�˵����ƶ�����
		int direct = 0;
		//��¼�Ƿ��м�����
		bool isPress = false;

		while (_kbhit())
		{
			key = _getch();
			isPress = true;
		}
		switch (key){
		case 'w':
		case 'W':
		case '8':
		case  72:
			if (press == 1)
				press = 6;
			else
				--press;
			direct = 0;
			break;
		case 's':
		case 'S':
		case '2':
		case  80:
			if (press == 6)
				press = 1;
			else
				++press;
			direct = 1;
			break;
			//������enter�����ҷ����ʱ��ȷ��ѡ��
		case   13:
		case   77:
			enterGame = true;
		default:
			break;
		}

		switch (press)
		{
		case 1:
			//��ԭǰһ��ѡ����������ɫΪ�˵���ɫ������direct���ж��ĸ�Ϊǰһ���û���ѡ��
			//ֻ���ڰ��¼�ʱ�Ž��и�����ʾ,���ڱ�����˸����ʵ��ѡ���ѡ����ɫ�ı仯��ͬ
			if (isPress)
			{
				if (direct)
				{
					//�������,��ԭ����һ��ѡ��������ɫ,��case 6��ͬ
					SetConsoleTextAttribute(myHandle, 0xE);
					gotoxy((MAX_RANDS - WALL_X_BEGIN) / 2 + 6, (MAX_ROWS - WALL_Y_BEGIN) / 2 - 3);
					printf(" �˳���Ϸ");
				}
				else
				{
					//�������,��ԭ����һ��ѡ��������ɫ����case 2��ͬ
					SetConsoleTextAttribute(myHandle, 0xE);
					gotoxy((MAX_RANDS - WALL_X_BEGIN) / 2 - 2, (MAX_ROWS - WALL_Y_BEGIN) / 2 - 3);
					printf(" ��ʱģʽ");
				}
				SetConsoleTextAttribute(myHandle, 0xB);
				gotoxy((MAX_RANDS - WALL_X_BEGIN) / 2 - 4, (MAX_ROWS - WALL_Y_BEGIN) / 2 - 3);
				printf("*����ģʽ");
			}
			break;
		case 2:
			if (isPress)
			{
				if (direct)
				{
					SetConsoleTextAttribute(myHandle, 0xE);
					gotoxy((MAX_RANDS - WALL_X_BEGIN) / 2 - 4, (MAX_ROWS - WALL_Y_BEGIN) / 2 - 3);
					printf(" ����ģʽ");
				}
				else
				{
					SetConsoleTextAttribute(myHandle, 0xE);
					gotoxy((MAX_RANDS - WALL_X_BEGIN) / 2 - 0, (MAX_ROWS - WALL_Y_BEGIN) / 2 - 3);
					printf(" ����ģʽ");
				}
				SetConsoleTextAttribute(myHandle, 0xB);
				gotoxy((MAX_RANDS - WALL_X_BEGIN) / 2 - 2, (MAX_ROWS - WALL_Y_BEGIN) / 2 - 3);
				printf("*��ʱģʽ");
			}
			break;
		case 3:
			if (isPress)
			{
				if (direct)
				{
					SetConsoleTextAttribute(myHandle, 0xE);
					gotoxy((MAX_RANDS - WALL_X_BEGIN) / 2 - 2, (MAX_ROWS - WALL_Y_BEGIN) / 2 - 3);
					printf(" ��ʱģʽ");
				}
				else
				{
					SetConsoleTextAttribute(myHandle, 0xE);
					gotoxy((MAX_RANDS - WALL_X_BEGIN) / 2 + 2, (MAX_ROWS - WALL_Y_BEGIN) / 2 - 3);
					printf(" ����ģʽ");
				}
				SetConsoleTextAttribute(myHandle, 0xB);
				gotoxy((MAX_RANDS - WALL_X_BEGIN) / 2 - 0, (MAX_ROWS - WALL_Y_BEGIN) / 2 - 3);
				printf("*����ģʽ");
			}
			break;
		case 4:
			if (isPress)
			{
				if (direct)
				{
					SetConsoleTextAttribute(myHandle, 0xE);
					gotoxy((MAX_RANDS - WALL_X_BEGIN) / 2 - 0, (MAX_ROWS - WALL_Y_BEGIN) / 2 - 3);
					printf(" ����ģʽ");
				}
				else
				{
					SetConsoleTextAttribute(myHandle, 0xE);
					gotoxy((MAX_RANDS - WALL_X_BEGIN) / 2 + 4, (MAX_ROWS - WALL_Y_BEGIN) / 2 - 3);
					printf(" ��Ϸ����");
				}
				SetConsoleTextAttribute(myHandle, 0xB);
				gotoxy((MAX_RANDS - WALL_X_BEGIN) / 2 + 2, (MAX_ROWS - WALL_Y_BEGIN) / 2 - 3);
				printf("*����ģʽ");
			}
			break;
		case 5:
			if (isPress)
			{
				if (direct)
				{
					SetConsoleTextAttribute(myHandle, 0xE);
					gotoxy((MAX_RANDS - WALL_X_BEGIN) / 2 + 2, (MAX_ROWS - WALL_Y_BEGIN) / 2 - 3);
					printf(" ����ģʽ");
				}
				else
				{
					SetConsoleTextAttribute(myHandle, 0xE);
					gotoxy((MAX_RANDS - WALL_X_BEGIN) / 2 + 6, (MAX_ROWS - WALL_Y_BEGIN) / 2 - 3);
					printf(" �˳���Ϸ");
				}

				SetConsoleTextAttribute(myHandle, 0xB);
				gotoxy((MAX_RANDS - WALL_X_BEGIN) / 2 + 4, (MAX_ROWS - WALL_Y_BEGIN) / 2 - 3);
				printf("*��Ϸ����");
			}

			break;

			//������������������һ����˸Ч��
			/*
			SetConsoleTextAttribute(myHandle, 0xB);
			gotoxy((MAX_RANDS - WALL_X_BEGIN) / 2 + 4, (MAX_ROWS - WALL_Y_BEGIN) / 2 - 3);
			printf("*��Ϸ����");break;
			*/
		case 6:
			if (isPress)
			{
				if (direct)
				{
					SetConsoleTextAttribute(myHandle, 0xE);
					gotoxy((MAX_RANDS - WALL_X_BEGIN) / 2 + 4, (MAX_ROWS - WALL_Y_BEGIN) / 2 - 3);
					printf(" ��Ϸ����");
				}
				else
				{
					SetConsoleTextAttribute(myHandle, 0xE);
					gotoxy((MAX_RANDS - WALL_X_BEGIN) / 2 - 4, (MAX_ROWS - WALL_Y_BEGIN) / 2 - 3);
					printf(" ����ģʽ");
				}
				SetConsoleTextAttribute(myHandle, 0xB);
				gotoxy((MAX_RANDS - WALL_X_BEGIN) / 2 + 6, (MAX_ROWS - WALL_Y_BEGIN) / 2 - 3);
				printf("*�˳���Ϸ");
			}
			break;
		default:
			break;
		}

		//������뻺����
		fflush(stdin);
	} while (!enterGame);

	//����Ϊ�˵����������
	//���˴�Ϊִ�в˵��е�ѡ��
	gameEnter(press);
}



//����ģʽ
void normalGame()
{
	//����ģʽ�����õ�ͼˢ��Ƶ��,��ͬ
	setFps();
	do{
		system("cls");
		prepareGame();
		prepareShow();
		startGame();
		releseSnake();
	} while (_getch() != 'N');
}

//������д�ĸ����ܺ������ݾ������������
//����ģʽ,��Ҫ����startGame����ƶ������������������ģ�����
//�ڸ������ٶ�(�ڵȼ�9��)��ʱ���½�����Ϸ�������еȼ�����
void limitTimeGame()
{
	setFps();
	do{
		system("cls");
		prepareGame();
		prepareShow();

		//���õȼ�Ϊ9
		Level = 9;

		//����ģʽ�µ�ʱ����
		limitGame_BeginMarkTime = clock();
		do{
			show();
			showLimitCurrentTime();
			Sleep(setLevel());
			move(snakeHeadPoint);
			moved_procces_Limit();
			speedCaclate();
			isTimeOver();
			if (isEatFood && !Pause)
			{
				gainScore();
			}

			if (GameOver)
				showGameOver();
		} while (!GameOver);
		releseSnake();
	} while (_getch() != 'N');
}

//����ģʽ�������������������û�Ե�ʳ��Ĵ���
void perfectGame()
{
	setFps();
	int tmpLive = 0;
	//���û�ѡ�����׶�
	system("cls");
	gotoxy((WALL_X_END - WALL_X_BEGIN) / 2 - 1, (WALL_Y_END - WALL_Y_BEGIN) / 2 - 6);
	SetConsoleTextAttribute(myHandle, 0xA);
	printf("Easy or Hard��(E/H)E");
	gotoxy((WALL_X_END - WALL_X_BEGIN) / 2 - 1, (WALL_Y_END - WALL_Y_BEGIN) / 2 - 6);
	printf("Input: ");
	//Ĭ��ΪEasy
	if (_getch() != 'H')
		tmpLive = 1;
	else
		tmpLive = 0;

	//������뻺��
	fflush(stdin);

	do{
		system("cls");
		prepareGame();
		//�������������
		Live = tmpLive;
		prepareShow();
		startGame();
		releseSnake();
	} while (_getch() != 'N');
}

//����ģʽ����������ٶ�(������ٶ�Ϊ���)���ȼ������Ժ�С�Ĳ���
void crazyGame()
{
	//����ˢ��Ƶ��
	setFps();
	//��ʼ������
	int tmpFps[11] = { fps[10], fps[10] - 1, fps[10] - 2, fps[10] - 3, fps[10] - 4,
		fps[10] - 5, fps[10] - 6, fps[10] - 7, fps[10] - 8, fps[10] - 9, fps[10] - 10 };
	//���鿽��
	memcpy(fps, tmpFps, sizeof(int) * 11);

	do{
		system("cls");
		prepareGame();
		prepareShow();
		startGame();
		releseSnake();
	} while (_getch() != 'N');
	/*
	//�ɲ���������ٶ���Ϸ��ȥ����������
	do{
	system("cls");
	prepareGame();
	//���õȼ�Ϊ10
	Level = 10;
	prepareShow();
	//����ģʽ����ֻ���ȼ���Ϊ10�������startGame,ȥ����������
	do{
	show();
	Sleep(setLevel());
	move(snakeHeadPoint);
	speedCaclate();
	if(isEatFood && !Pause)
	{
	gainScore();
	}

	if(GameOver)
	showGameOver();
	}while(!GameOver);

	releseSnake();
	}while(getch()!= 'N');
	*/
}

//��ʾ������Ϣ
void showHelp()
{
	system("cls");
	SetConsoleTextAttribute(myHandle, 0xB);
	gotoxy(0, 0);
	printf("Help:");

	gotoxy(1, 1);
	printf("����ģʽ��");
	gotoxy(2, 2);
	printf("����ģʽ��Ϊ����Ϸ�ı�׼ģʽ������ģʽ����Ϸ�����ǻ��ڴ�ģʽ��");

	gotoxy(4, 1);
	printf("��ʱģʽ:");
	gotoxy(5, 2);
	printf("��ʱģʽΪ�ڹ涨��ʱ���ڣ����趨���ٶȣ��Լ�������ǽ���������");
	gotoxy(6, 2);
	printf("���£��Ƚϵ÷ֵĶ���!");

	gotoxy(8, 1);
	printf("����ģʽ:");
	gotoxy(9, 2);
	printf("����ģʽΪ������ģʽ�£������������û�Ե�ʳ�����Ĵ�С�����ѵ�");
	gotoxy(10, 2);
	printf("ģʽ�£�����Ҫһ����©�ĳԵ�ʳ��");

	gotoxy(12, 1);
	printf("����ģʽ:");
	gotoxy(13, 2);
	printf("����ģʽΪ������ģʽ�£�������ٶȽ�����Ϸ����ս�ٶ��뼤��!");
	gotoxy(MAX_RANDS, 0);
	printf("��Q�������˵�");
}

//������
int main(void)
{
	gameInit();
	//һֱ����ѭ�������ڲ˵�ѡ����ѡ���˳���Ϸ
	do{
		//һ��ѭ��ֻ����һ�����˵�
		mainMenuAndGameEnter();
	} while (true);
	return 0;
}

