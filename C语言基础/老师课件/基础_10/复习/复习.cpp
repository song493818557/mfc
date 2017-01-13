// 复习.cpp : 定义控制台应用程序的入口点。
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
	     //父类中属性       继承方式     在子类中
	//01    public           public       public      接口继承（父类中的公有函数在子类中还是公有的）
	//02    protected        public       protected
	//03    private          public       不能访问

	//04    public           procted      procted     实现继承（没有阻断和孙子类的联系）
	//05    procted          procted      procted
	//06    private          procted      不能访问

	//07    public           private      private     实现继承（阻断了和孙子类的联系）
	//08    protected        private      private  
	//09    private          private      不能访问
};



int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

