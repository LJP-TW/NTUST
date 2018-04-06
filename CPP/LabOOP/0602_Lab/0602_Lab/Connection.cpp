// Name: LDJ
// Date: 2018/04/01
// Last Update: 2018/04/01
// Problem statement: 紀錄User的連線資訊
#include "Connection.h"

// 使用一個32bit的整數表示一組IP，如2130706433表示127.0.0.1
Connection::Connection(unsigned int ipAddress, unsigned short port) {
	this->ipAddress = ipAddress;
	this->port = port;
}

// 使用四個8bit的整數表示一組IP，如127, 0, 0, 1表示127.0.0.1
Connection::Connection(unsigned char ipField1, unsigned char ipField2, unsigned char ipField3, unsigned char ipField4, unsigned short port) {
	this->ipAddress = (ipField1 << 24) + (ipField2 << 16) + (ipField3 << 8) + ipField4;
	this->port = port;
}

// 讓此物件可以直接使用<<輸出到ostream
std::ostream& operator<<(std::ostream& outputStream, const Connection& connection) {
	// 如IP是0則輸出unknown，否則輸出以點分隔的格式
	if (connection.ipAddress) {
		outputStream << "IP: " << (connection.ipAddress >> 24 & 0xff) << "." << (connection.ipAddress >> 16 & 0xff) << "." << (connection.ipAddress >> 8 & 0xff) << "." << (connection.ipAddress & 0xff);
	}
	else {
		outputStream << "IP: unknown";
	}

	// 如port是0則輸出unknown，否則輸出其值
	if (connection.port) {
		outputStream << ", Port: " << connection.port;
	}
	else {
		outputStream << ", Port: unknown";
	}

	return outputStream;
}
