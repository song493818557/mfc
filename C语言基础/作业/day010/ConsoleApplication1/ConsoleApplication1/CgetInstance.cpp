#include "stdafx.h"
#include "CgetInstance.h"
Singleton::Singleton(){
}
Singleton::Singleton(const Singleton&){
}
Singleton& Singleton::operator=(const Singleton&){
   return *instance;
}

//在此处初始化
Singleton* Singleton::instance = new Singleton();
Singleton* Singleton::getInstance(){
	return instance;
}
