#include <iostream>
#include <sstream>
#include <string>
#include "bst.h"

using namespace std;

Bst bst;

void init()
{
	string buf;
	cout << "��J�Ʀr��@��, �ΪŮ�j�}" << endl;
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
	cout << "�Ш̷ӤU�C�榡��J���O" << endl;
	cout << "[���O] [�ƭ�] (�ƭ�2)" << endl;
	cout << "���O:" << endl;
	cout << "i: Insertions [�ƭ�]" << endl;
	cout << "d: Deletions [�ƭ�]" << endl;
	cout << "a: Avg [Rank1] [Rank2]" << endl;
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
		else if (i == 'a')
		{
			int data2;
			iss >> data2;
			try
			{
				cout << bst.avg(data, data2) << endl;
			}
			catch (BstMinelementException& e)
			{
				cout << e.msg() << endl;
			}
		}
	}


	return 0;
}