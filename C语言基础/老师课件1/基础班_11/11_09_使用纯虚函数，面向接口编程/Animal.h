#pragma once
class CAnimal
{
public:
	CAnimal();
	~CAnimal();
	//���麯��������ӿ�
	virtual void eat() = 0;//�淶�������Ըýӿ���һ��ʵ��

	int getAge() const { return m_age; }
	void setAge(int val) { m_age = val; }
protected:
	int m_age;
};

