// Name: 張書銘 B10615025
// Date: Apr. 5, 2018
// Last Update: Apr. 5, 2018
// Problem statement: WebChat
#include "User.h"

int User::userCount = 0;

User::User(std::string name) : name(name), connection(0, 0)
{
	++userCount;
}

User::User(std::string name, unsigned int ipAddress) : name(name), connection(ipAddress, 0)
{
	++userCount;
}

User::User(std::string name, unsigned int ipAddress, unsigned short port) : name(name), connection(ipAddress, port)
{
	++userCount;
}

User::User(std::string name, unsigned char ipField1, unsigned char ipField2, unsigned char ipField3, unsigned char ipField4) : name(name), connection(ipField1, ipField2, ipField3, ipField4, 0)
{
	++userCount;
}

User::User(std::string name, unsigned char ipField1, unsigned char ipField2, unsigned char ipField3, unsigned char ipField4, unsigned short port) : name(name), connection(ipField1, ipField2, ipField3, ipField4, port)
{
	++userCount;
}

User::User(const User& user1) : name(user1.name), connection(user1.connection)
{
	++userCount;
}

User::~User()
{
	--userCount;
}

std::ostream & operator<<(std::ostream& outputStream, const User& user1)
{
	outputStream << "Name: " << user1.name << ", " << user1.connection;
	return outputStream;
}
