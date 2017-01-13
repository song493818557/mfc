// 8-6.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "stdio.h"
#include <stdlib.h>

struct  testa
{
	float math;
	float english;
	float chinese;

};
struct testb{
	char Name[20];
	int StuNumb;
	float Score;
	char Address[50];
};

int _tmain(int argc, _TCHAR* argv[])
{


	testa Scores[4] = { { 67.5, 44.5, 55 }, { 97.5, 74.5, 64 }, { 64.5, 47.5, 94 }, { 57.5, 94.5, 64 } };
	/*方法1
	testb Alldata[4] = {
	{ "xiaohua", 230, 0, "北京" },
	{ "xiaoming", 231, 0, "上海" },
	{ "xiaoha", 232, 0, "南昌" },
	{ "xiaohu", 233, 0, "深圳" } };
	*/
	
	/*方法1
	testa * tmp;
	tmp = Scores;
	testb * tmpa;
	tmpa = Alldata;

	for (int i = 0; i < 4;i++){
	float bb = tmp[i].chinese + tmp[i].english + tmp[i].math;
	//print("");
	Alldata[i].Score = bb;

	}*/
	/*方法二*/
	testb Alldata[4] = {
		{ "xiaohua", 230, Scores[0].chinese + Scores[0].english + Scores[0].math, "北京" },
		{ "xiaoming", 231, Scores[1].chinese + Scores[1].english + Scores[1].math, "上海" },
		{ "xiaoha", 232, Scores[2].chinese + Scores[2].english + Scores[2].math, "南昌" },
		{ "xiaohu", 233, Scores[3].chinese + Scores[3].english + Scores[3].math, "深圳" } };
	
	for (int i = 0; i < 4; i++){
		printf("%s,%d,%0.2f,%s\n", Alldata[i].Name, Alldata[i].StuNumb, Alldata[i].Score, Alldata[i].Address);


	}
	return 0;
}

