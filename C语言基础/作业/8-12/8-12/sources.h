#include <iostream>
using std::endl;
using std::cin;
using std::cout;
/*��ҵ5����*/
class _lifangti
{
public:
	void shezhi()
	{
		 this->chang = 5;
		 this->gao = 6;
		 this->kuan = 7;
	}
	void shuchu(){
		cout << this->chang*this->gao*this->kuan;
	}


private:
	int chang = 0;
	int kuan = 0;
	int gao = 0;
};

/*��ҵ6����*/
class _lifangtia
{
public:
	void shezhi()
	{
		this->chang = 5;
		this->gao = 6;
		this->kuan = 7;
	}
	void shuchu(){
		cout << &this->chang;
	}

	int chang = 0;
	int kuan = 0;
	int gao = 0;
private:
	
};
/*��ҵ7����*/
class _man
{
public:
	char name[20];
	short age;
	float height;
	float weight;
	float Health;
	void get_Health(){
		this->Health = (this->weight) / (this->height * this->height * this->height);
	}
	

private:

};
/*��ҵ8������*/
class  _count_Machine{
public:
	//�����û������ѡ��
	int user_input(){
		 cin >> this->user_inputa;
		 return this->user_inputa;
	}
	//�����û�����ı��ʽ
	void expression(){
		cin >> this->now_expression;
		switch (this->now_expression)
		{
		case 1:
			//call(jia);
			this->now_symbol = '+'; break;
		case 2:
			//call(jian);
			this->now_symbol = '-'; break;
		case 3:
			//call(cheng);
			this->now_symbol = '*'; break;
		case 4:
			//call(chu);
			this->now_symbol = '/'; break;
		case 5:
			//call(mo);
			this->now_symbol = '%'; break;
		default:
			break;
		}
	}
	//����û�����ı��ʽ
	void delete_expression(){
		this->now_expression=0;
		this->now_symbol = ' ';
	}
	//�����ǰ�ı��ʽ ��ǰ�ļ�����  
	void outputresult(){
		
		//this->result = this->aa + this->bb;
		cout << "��ǰ�ı��ʽ��:" << this->now_symbol << endl << "��ǰ����������:" << this->result << endl;
	//<< "��ǰ�ı��ʽ��:" << this->now_symbol << endl
	}
	//�����û�����ı��ʽ
	void input_number(){
		scanf_s("%d %d", &this->aa, &this->bb);
		
		switch (this->now_expression)
		{
		case 1:
			call(jia); break;
			//this->now_symbol = '+';
		case 2:
			call(jian); break;
			//this->now_symbol = '-';
		case 3:
			call(cheng); break;
			//this->now_symbol = '*';
		case 4:
			call(chu); break;
			//this->now_symbol = '/';
		case 5:
			call(mo); break;
			//this->now_symbol = '%';
		default:
			break;
		}
	}
	//�жϴ��ݸ��Ǹ�����
	int  call(int(*p)( int aaa, int bbb)){
		this->result = (*p)(this->aa, this->bb);
		return result;
	}
	static int jia(int aa, int bb){
		return  aa + bb;
	}
	static int jian(int aa, int bb){
		return  aa - bb;

	}
	static int cheng(int aa, int bb){
		return  aa * bb;
	}
	static int chu(int aa, int bb){
		return  aa / bb;
	}
	static int mo(int aa, int bb){
		return  aa % bb;
	}
private:
	int aa =0;
	int bb=0;
	int result =0;
	int user_inputa =1;
	int now_expression = 1;
	char now_symbol = '+';
};
_count_Machine jisuanqi;