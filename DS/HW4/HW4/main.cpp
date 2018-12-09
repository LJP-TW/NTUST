#include <iostream>
#include <sstream>
#include <string>
#include "bst.h"

using namespace std;

Bst bst;

void init()
{
	string buf;
	cout << "輸入數字於一行, 用空格隔開" << endl;
	getline(cin, buf);

	// Initial
	istringstream iss(buf);
	int num;

	while (iss >> num)
	{
		try
		{
			bst.ins(num);
		}
		catch (BstInsertException& e)
		{
			cout << e.msg() << endl;
		}
	}
}

int main() 
{
	init();

	string buf;
	cout << "請依照下列格式輸入指令" << endl;
	cout << "[指令] [數值]" << endl;
	cout << "指令:" << endl;
	cout << "i: insert" << endl;
	cout << "d: delete" << endl;
	cout << "m: minelement" << endl;
	while (true)
	{
		char i;
		int data;

		getline(cin, buf);
		istringstream iss(buf);
		
		iss >> i >> data;

		if (i == 'i')
		{
			try
			{
				bst.ins(data);
			}
			catch (BstInsertException& e)
			{
				cout << e.msg() << endl;
			}
		}
		else if (i == 'd')
		{
			try
			{
				bst.del(data);
			}
			catch (BstDeleteException& e)
			{
				cout << e.msg() << endl;
			}
		}
		else if (i == 'm')
		{
			try
			{
				cout << bst.minelement(data) << endl;
			}
			catch (BstMinelementException& e)
			{
				cout << e.msg() << endl;
			}
		}
	}
	

	return 0;
}