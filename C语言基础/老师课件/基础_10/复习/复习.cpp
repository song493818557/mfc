// ��ϰ.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"

class CBase
{

	//private
	//public
	//protected

public:
	int a;
	void fun()
	{}
};

class CTest:public CBase
	      //protected
		  //private
{
	     //����������       �̳з�ʽ     ��������
	//01    public           public       public      �ӿڼ̳У������еĹ��к����������л��ǹ��еģ�
	//02    protected        public       protected
	//03    private          public       ���ܷ���

	//04    public           procted      procted     ʵ�ּ̳У�û����Ϻ����������ϵ��
	//05    procted          procted      procted
	//06    private          procted      ���ܷ���

	//07    public           private      private     ʵ�ּ̳У�����˺����������ϵ��
	//08    protected        private      private  
	//09    private          private      ���ܷ���
};



int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

