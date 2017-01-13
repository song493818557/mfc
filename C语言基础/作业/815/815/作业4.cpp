// 815.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <stdlib.h>
using std::cout;
using std::cin;
using std::endl;
using namespace std;

class Cvehicle
{
public: 
	int m_wheels;
	float m_weight;
private:
	
};
class Csmallcar :public Cvehicle
{
public: 
	Csmallcar(int wheels, float weight, int passenger_load = 0) : m_passsenger_load(passenger_load){
		m_weight = wheels;
		m_wheels = weight;
	}
	void outinfo(){
		cout << m_passsenger_load << m_weight << m_wheels;
	}
private:
	int m_passsenger_load;
};
class Ctruck :public Cvehicle
{
public: 
	Ctruck(int passenger_load, float payload, int wheels, float weight) :m_payload(payload), m_passenger_load(passenger_load){
		m_weight = wheels;
		m_wheels = weight;
	}
	void outinfo(){
		cout << m_payload << m_passenger_load << m_weight << m_wheels;
	}
private:
	int m_passenger_load;
	float m_payload;
};
int _tmain(int argc, _TCHAR* argv[])
{
	Ctruck onetruck(6,3.5,4,5);
	onetruck.outinfo();
	Csmallcar onecar(6, 4, 5);
	onecar.outinfo();
	return 0;
}

