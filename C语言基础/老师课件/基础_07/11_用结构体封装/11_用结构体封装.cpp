// 11_�ýṹ���װ.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <string.h>
struct _BINGXIANG;

void OpenDoor(_BINGXIANG * pMy)
{
	pMy->bOpenDoor = true;
}
void ShowInfo(_BINGXIANG * pMy)
{
	printf("���ƣ�%s,����:%d", pMy->Name, pMy->rongliang);
}
void InitInfo(_BINGXIANG * pMy)
{
	strcpy_s(pMy->Name,20, "����");
	pMy->rongliang = 100;
}

typedef void (*FUN)(_BINGXIANG * );



typedef struct _BINGXIANG
{
	char Name[20];
	int rongliang;
	bool bOpenDoor;
	FUN  pfnOpen;
	FUN  pfnShow;
	FUN  pfnInit;
}BINGXIANG;


int _tmain(int argc, _TCHAR* argv[])
{
	BINGXIANG stc;
	stc.pfnOpen = OpenDoor;
	stc.pfnShow = ShowInfo;
	stc.pfnInit = InitInfo;
	//InitInfo(&stc);


	stc.pfnInit(&stc);
	return 0;
}

