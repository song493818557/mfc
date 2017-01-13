#pragma once
#ifndef _SINGLETON_H_
#define _SINGLETON_H_

//����ģʽ2
class Singleton{
public:
	static Singleton* getInstance();
private:
	Singleton();
	//�Ѹ��ƹ��캯����=������Ҳ��Ϊ˽��,��ֹ������
	Singleton(const Singleton&);
	Singleton& operator=(const Singleton&);
	static Singleton* instance;
};

#endif