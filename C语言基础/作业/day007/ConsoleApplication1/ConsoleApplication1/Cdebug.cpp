#include "stdafx.h"
#include <iostream>
#include "Cdebug.h"
using namespace std;
Cmyclass::Cmyclass(){
	cout << "constructing normally. \n";
}
Cmyclass::Cmyclass(int m) :number(m){ 
		cout << "constructing with a number: "<<number<<endl;
	 
}
Cmyclass::~Cmyclass(){ cout << "Destructing . \n"; }
void Cmyclass::Display(){
	cout << "Display   a number:  " << number << endl;
}

 