#pragma once
#ifndef _SINGLETON_H_
#define _SINGLETON_H_

//懒汉模式2
class Singleton{
public:
	static Singleton* getInstance();
private:
	Singleton();
	//把复制构造函数和=操作符也设为私有,防止被复制
	Singleton(const Singleton&);
	Singleton& operator=(const Singleton&);
	static Singleton* instance;
};

#endif