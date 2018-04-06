// Name: LDJ
// Date: 2018/04/01
// Last Update: 2018/04/01
// Problem statement: 紀錄User的連線資訊
#pragma once
#include <iostream>

class Connection {
public:
	// 使用一個32bit的整數表示一組IP，如2130706433表示127.0.0.1，如不輸入則預設為0
	Connection(unsigned int ipAddress, unsigned short port);
	// 使用四個8bit的整數表示一組IP，如127, 0, 0, 1表示127.0.0.1
	Connection(unsigned char ipField1, unsigned char ipField2, unsigned char ipField3, unsigned char ipField4, unsigned short port);
	// 讓此物件可以直接使用<<輸出到ostream
	friend std::ostream& operator<<(std::ostream& outputStream, const Connection& connection);
private:
	// 連線使用的IP，0表示unknown
	unsigned int ipAddress;
	// 連線使用的port，0表示unknown
	unsigned short port;
};
