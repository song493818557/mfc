// ��������-�������÷�ʽ.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"

// C���÷�ʽ

int _cdecl CDCall(int n1, char* p2,int n3)
{
	return n1;
}


// ��׼���÷�ʽ
int _stdcall StdCall(int n1 , char* p2 , int n3)
{
	return n1;
}

// ���ٵ��÷�ʽ
int _fastcall FastCall(int n1 , char* p2 , int n3)
{
	
	return n3;
}

class MyClass
{
public:
	// C++ ������Ա�����ĵ��÷�ʽ
	int ThisCall(int n1 , char* p2 , int n3)
	{
		return  n1 ;
	}
};




// �㺯��
// �����㺯���Ĺؼ��� ��  __declspec(naked)
// �����ĵ��÷�ʽ �� _stdcall  
// ���㺯���У������Լ�д������������ջ�ռ�
int __declspec(naked) nakedFunction(int n , char* p2 , int n3)
{
	_asm
	{
	push ebp;
	mov ebp,esp
	}

	_asm
	{
		mov eax , n3;
		mov esp , ebp;
		pop ebp;
		_asm ret 3 * 4
	}
}




int _tmain(int argc, _TCHAR* argv[])
{
	int nRet = 0;
	
	// ע���βδ��ݵ�˳��
	// ע��ƽ���ջ�ķ�ʽ

	// C���÷�ʽ
	nRet = CDCall(1 , "123" , 2);


	// ��׼����
	nRet = StdCall(1 , "123" , 2);

	// ���ٵ���
	nRet = FastCall(1 , "123" , 2);

	MyClass obj;
	// this call
	obj.ThisCall(1 , "123" , 2);


	//nRet = nakedFunction(1 , "123" , 2);
	return 0;
}

