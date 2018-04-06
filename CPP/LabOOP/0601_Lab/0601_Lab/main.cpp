// Name: 張書銘 B10615025
// Date: Apr. 5, 2018
// Last Update: Apr. 5, 2018
// Problem statement: MonsterCreator
#include <iostream> 
#include <vector>
#include "monster.h"

using namespace std;

// print menu
void menu();

// main funtion
int main() {
	int features;
	//會用map的人推薦用map
	//當然用vector也是ok的
	vector<Monster> monster;
	
	string name;
	float hp;
	float damage;
	float defense;
	float speed;

	menu();
	while (cin >> features)
	{
		if (features == 0)
		{
			cout << "Please enter monster state" << endl;
			cin >> name >> hp >> damage >> defense >> speed;
			
			// Push a new one
			monster.push_back(Monster(name, hp, damage, defense, speed));
		}
		else if (features == 1)
		{
			cout << "Please enter monster name : ";
			cin >> name;
			
			// Find
			for (int i = 0; i < monster.size(); ++i)
			{
				if (monster[i].GetName() == name)
				{
					monster[i].PrintAllState();
					break;
				}
			}
		}
		else if (features == 2)
		{
			cout << "Please enter monster name : ";
			cin >> name;
			
			// Find
			for (int i = 0; i < monster.size(); ++i)
			{
				if (monster[i].GetName() == name)
				{
					cout << "Please enter new state : ";
					cin >> name >> hp >> damage >> defense >> speed;
					monster[i].SetName(name);
					monster[i].SetHP(hp);
					monster[i].SetDamage(damage);
					monster[i].SetDefense(defense);
					monster[i].SetSpeed(speed);
					break;
				}
			}
		}

		//謝謝我吧哈哈哈
		cout << endl;
		menu();
	}
	return 0;
}

// print menu
void menu()
{
	cout << "Create monster enter 0" << endl;
	cout << "Check state enter 1" << endl;
	cout << "Change state enter 2" << endl;
	cout << "Feature : ";
}
