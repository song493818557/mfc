// ConsoleApplication3.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
class student{
public:
	student() :m(2){ printf("student"); }
	~student() { printf("student"); }
	int m;
private:
	
};
class graduatestudent :public student{
public:
	graduatestudent() :a(3){ printf("graduatestudent"); }
	~graduatestudent()   { printf("~graduatestudent"); }
	int a;
private:
	
};

int _tmain(int argc, _TCHAR* argv[])
{
	graduatestudent gs;
	student s = gs;// s复制了 GS对象中的student部分 构成了名副其实的student对象实体
	student & t = gs; // T虽然也构造了student对象 但是 t是引用 它在图中代表GS对象中的不可分离的student部分  只能操作GS的STUDENT数据
	student * p = &gs;//p是student指针 指向graduatestudent对象的GS的首地址 它恰好也是其中student对象部分的首地址  只能操作GS的STUDENT数据
	/*gs = s;  若用父类对象S给子类对象GS赋值 因为父类中的数据不充分  不含有子类全部的信息 所以拒绝执行
	graduatestudent * pgs = &s; 用父类对象的地址&s给子类对象指针PGS赋值 也是非法的 虽然地址操作不设计对象的重建 
	  因此 我们将不考虑父类到子类的转换 专门考察子类对象就是父类对象这一基本意义和前提 
	*/ 
	t.m = 3;
	int x, y;
	x = y = 3;
	scanf_s("%d",&x);
	return 0;
}

