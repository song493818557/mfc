#include "stdafx.h"
#include "Conly.h"
//�ⲿ��ʼ�� before invoke main
const SingletonStatic* SingletonStatic::m_instance = new SingletonStatic;
//��ȷ��������
CSingleton* CSingleton::m_pInstance = new CSingleton();