#pragma once
#include "Cmysql.h"
#include <iostream>
using std::string;
class Cbase64
{
public:
	Cbase64();
	~Cbase64();  
	string base64_chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
	static inline bool is_base64(unsigned char c) {
		return (isalnum(c) || (c == '+') || (c == '/'));
	}

	string base64_encode( char * bytes_to_encode, unsigned int in_len);

	string base64_decode(string const& encoded_string);
};

