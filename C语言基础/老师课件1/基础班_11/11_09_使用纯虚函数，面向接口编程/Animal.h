#pragma once
class CAnimal
{
public:
	CAnimal();
	~CAnimal();
	//纯虚函数，定义接口
	virtual void eat() = 0;//规范子类必须对该接口有一个实现

	int getAge() const { return m_age; }
	void setAge(int val) { m_age = val; }
protected:
	int m_age;
};

