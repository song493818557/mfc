#pragma once
#include "Clogin.h"  
#include <iostream>
using std::string;
class Creg
{
public:
	Creg();
	~Creg();
	int uid;
	string user_name;
	string password;
	string ip_address;
	string reg_time;
	string last_login;
};

