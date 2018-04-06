#include <iostream>
#include <cstdlib>
#include "User.h"
/*
此程式應該輸出以下內容
Active User: 4
Name: Enrique, IP: 127.0.0.1, Port: 443
Name: Gerardo, IP: 7.91.205.21, Port: 8080
Name: Austyn, IP: 58.222.104.177, Port: unknown
Name: Troy, IP: unknown, Port: unknown
*/
int main() {
	User users[] = {
		{ "Enrique", 127, 0, 0, 1, 443 },
		{ "Gerardo", 123456789, 8080 },
		{ "Austyn", 987654321 },
		{ "Troy" },
	};
	std::cout << "Active User: " << User::userCount << std::endl;
	for (int i = 0; i < 4; i++) {
		std::cout << users[i] << std::endl;
	}
	system("pause");
	return 0;
}
