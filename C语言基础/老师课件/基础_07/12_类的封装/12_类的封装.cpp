// 12_类的封装.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include <string>

class BINGXIANG
{
public:
	void OpenDoor(){//在类内实现了
		bOpenDoor = true;
	}
	void ShowInfo(){
		printf("%d", this);
		printf("名称：%s,容量:%d", this->Name,this->rongliang);
	}
	void InitInfo(char buf[]){
		strcpy_s(Name, 20, buf);
		rongliang = 100;
	}
	int rongliang;
private:
	char Name[20];

	bool bOpenDoor;
};

class DAXIANG
{
public:
	void Zou();     //在类内声明

private:
	char Name[20];

	bool Weight;
};

void DAXIANG::Zou() //在类外实现
{
	printf("我正在走");
}

int _tmain(int argc, _TCHAR* argv[])
{
	BINGXIANG stc1;
	stc1.InitInfo("海尔");
	stc1.rongliang = 100;
	BINGXIANG stc2;
	stc2.InitInfo("美的");
	stc2.rongliang = 200;

	stc1.ShowInfo();
	printf("%d\n", &stc1);
	stc2.ShowInfo();
	printf("%d", &stc2);


	int a = 100;   //叫初始化
	a = 200;       //这个叫赋值
	int b(100);    //也叫初始化


	//BINGXIANG* p = &stc1;
	//p->ShowInfo();
	//InitInfo(&stc);
	return 0;
}

