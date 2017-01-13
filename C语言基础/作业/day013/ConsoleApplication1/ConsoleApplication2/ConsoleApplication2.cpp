// ConsoleApplication2.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h" 
#include "..\ConsoleApplication1\Ctree.h"


int _tmain(int argc, _TCHAR* argv[])
{
	Ctree ttree;
	ttree.insert(50);
	ttree.insert(25);
	ttree.insert(75);
	ttree.insert(12);
	ttree.insert(37);
	ttree.insert(60);
	ttree.insert(90);
	ttree.insert(68);
	ttree.insert(64);
	ttree.insert(127);
	ttree.insert(138);
	ttree.insert(154);
	ttree.insert(89);
	ttree.insert(121);
	ttree.insert(144);
	ttree.insert(17);
	ttree.insert(8);
	int b = ttree.Getheighta();
	ttree.show(0);
	ttree.Delete(50);
	ttree.show(0);
	ttree.Delete(154);
	ttree.show(0);
	ttree.Delete(90);
	ttree.show(0);
	return 0;
}

