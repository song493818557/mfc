// 8_04_函数重载与名称粉碎(C).cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

//重载(名称粉碎来实现)
//1.相同作用域
//2.同名函数
//3.参数不一样
int Add(int nNumA, int nNumB) {
	return nNumA + nNumB;
}
int Add(int nNumA, char cChar) {
	return nNumA + cChar;
}
extern "C" int Add(char nNumA, char cChar);

//返回值不同不能构成重载
// char Add(int nNumA, char nNumB) {
// 	return nNumA + nNumB;
// }
int main()
{
	Add(10, 20);
	Add(10, 'a');
	Add('a', 'b');
    return 0;
}

