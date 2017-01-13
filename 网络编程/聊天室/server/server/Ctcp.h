#pragma once
#include "Creg.h"

#pragma comment(lib,"ws2_32.lib")
class Ctcp
{
public:
	Ctcp();
	~Ctcp();
	bool openserver();
	bool closeserver();
};

