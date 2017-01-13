#include "stdafx.h"
#include "Conly.h"
//外部初始化 before invoke main
const SingletonStatic* SingletonStatic::m_instance = new SingletonStatic;
//正确申明方法
CSingleton* CSingleton::m_pInstance = new CSingleton();