// Name: 張書銘 B10615025
// Date: Apr. 5, 2018
// Last Update: Apr. 5, 2018
// Problem statement: WebChat
#pragma once
#include <iostream>
#include <string>
#include "Connection.h"

class User {
public:
	// 紀錄目前有多少User
	static int userCount;
	// User的名稱
	std::string name;
	// User的連線資訊
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
	
	// Copy Constructor, Vector 會用到
	User(const User&);

	// Destructor
	~User();

	// Operator Overloading
	friend std::ostream& operator << (std::ostream&, const User&);

};