// 12_��ķ�װ.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"

#include <string>

class BINGXIANG
{
public:
	void OpenDoor(){//������ʵ����
		bOpenDoor = true;
	}
	void ShowInfo(){
		printf("%d", this);
		printf("���ƣ�%s,����:%d", this->Name,this->rongliang);
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
	void Zou();     //����������

private:
	char Name[20];

	bool Weight;
};

void DAXIANG::Zou() //������ʵ��
{
	printf("��������");
}

int _tmain(int argc, _TCHAR* argv[])
{
	BINGXIANG stc1;
	stc1.InitInfo("����");
	stc1.rongliang = 100;
	BINGXIANG stc2;
	stc2.InitInfo("����");
	stc2.rongliang = 200;

	stc1.ShowInfo();
	printf("%d\n", &stc1);
	stc2.ShowInfo();
	printf("%d", &stc2);


	int a = 100;   //�г�ʼ��
	a = 200;       //����и�ֵ
	int b(100);    //Ҳ�г�ʼ��


	//BINGXIANG* p = &stc1;
	//p->ShowInfo();
	//InitInfo(&stc);
	return 0;
}

