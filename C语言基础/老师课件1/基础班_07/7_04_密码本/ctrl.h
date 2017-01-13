#pragma once
#include "draw.h"
void searchAllInfo(PASSWORD pwd[], int nCount); //PPASSWORD pPwd
void insertInfo(PASSWORD pwd[], int * pnCount);
void deleteInfo(PASSWORD pwd[], int * pnCount);
void alterInfo(PASSWORD pwd[], int  nCount);
void searchInfo(PASSWORD pwd[], int  nCount);

void SaveInfoA(PASSWORD pwd[],int nCount);
void SaveInfoB(PASSWORD pwd[],int nCount);
void readInfo(PPASSWORD * ppPwd, int * pnCount);