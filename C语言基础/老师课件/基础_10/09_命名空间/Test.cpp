#include "stdafx.h"
#include "Test.h"


int Test::g_num = 100;

void Test::Inner::fun()
{
	printf("Hello");
}