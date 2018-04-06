// Name: �i�ѻ� B10615025
// Date: Apr. 5, 2018
// Last Update: Apr. 5, 2018
// Problem statement: WebChat
#pragma once
#include <iostream>
#include <string>
#include "Connection.h"

class User {
public:
	// �����ثe���h��User
	static int userCount;
	// User���W��
	std::string name;
	// User���s�u��T
	Connection connection;

	// Constructor
	// Name
	User(std::string name);
	// Name, IP(32bits)
	User(std::string, unsigned int);
	// Name, IP(32bits), Port
	User(std::string, unsigned int, unsigned short);
	// Name, IP(4 * 8bits)
	User(std::string, unsigned char, unsigned char, unsigned char, unsigned char);
	// Name, IP(4 * 8bits), Port
	User(std::string, unsigned char, unsigned char, unsigned char, unsigned char, unsigned short);
	
	// Copy Constructor, Vector �|�Ψ�
	User(const User&);

	// Destructor
	~User();

	// Operator Overloading
	friend std::ostream& operator << (std::ostream&, const User&);

};