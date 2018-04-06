// Name: 張書銘 B10615025
// Date: Apr. 5, 2018
// Last Update: Apr. 5, 2018
// Problem statement: MonsterCreator
#include "monster.h"

Monster::Monster()
{
}

Monster::Monster(string name, float hp, float damage, float defense, float speed)
{
	this->name = name;
	this->hp = hp;
	this->damage = damage;
	this->defense = defense;
	this->speed = speed;
}

void Monster::SetName(string name)
{
	this->name = name;
}

void Monster::SetHP(float hp)
{
	this->hp = hp;
}

void Monster::SetDamage(float damage)
{
	this->damage = damage;
}

void Monster::SetDefense(float defence)
{
	this->defense = defence;
}

void Monster::SetSpeed(float speed)
{
	this->speed = speed;
}

void Monster::PrintAllState()
{
	cout << "Name : " << name << endl;
	cout << "Hp : " << hp << endl;
	cout << "Damage : " << damage << endl;
	cout << "Defence : " << defense << endl;
	cout << "Speed : " << speed << endl;
}

string Monster::GetName()
{
	return name;
}

float Monster::GetHP()
{
	return hp;
}

float Monster::GetDamage()
{
	return damage;
}

float Monster::GetDefence()
{
	return defense;
}

float Monster::GetSpeed()
{
	return speed;
}


Monster::~Monster()
{
}
