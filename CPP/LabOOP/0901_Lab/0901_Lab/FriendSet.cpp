// Name: 張書銘
// Date: Apr. 26, 2018
// Last Update: Apr. 26, 2018
// Problem statement: 我的朋友很少
#include <iostream>
#include "FriendSet.h"

FriendSet::FriendSet() : amount(0), pFriend(NULL)
{
}

FriendSet::FriendSet(int B) : amount(1)
{
	pFriend = new int[amount];
	pFriend[0] = B;
}

FriendSet::FriendSet(const FriendSet& other)
{
	amount = other.amount;
	pFriend = new int[amount];
	for (int i = 0; i < amount; ++i)
	{
		pFriend[i] = other.pFriend[i];
	}
}

FriendSet::~FriendSet()
{
	if (pFriend)
	{
		delete[] pFriend;
	}
}

bool FriendSet::findFriend(int target)
{
	for (int i = 0; i < amount; ++i)
	{
		if (pFriend[i] == target)
		{
			return true;
		}
	}
	return false;
}

int FriendSet::size()
{
	return amount;
}

void FriendSet::operator+=(FriendSet other)
{
	int *pOldFriend = pFriend;
	int oldAmount = amount;

	amount += other.amount;
	pFriend = new int[amount];

	for (int i = 0; i < oldAmount; ++i)
	{
		pFriend[i] = pOldFriend[i];
	}

	for (int i = oldAmount; i < amount; ++i)
	{
		pFriend[i] = other.pFriend[i - oldAmount];
	}

	delete[] pOldFriend;
}

void FriendSet::operator+=(int newFriend)
{
	int *pOldFriend = pFriend;
	int oldAmount = amount;

	amount += 1;
	pFriend = new int[amount];

	for (int i = 0; i < oldAmount; ++i)
	{
		pFriend[i] = pOldFriend[i];
	}

	pFriend[oldAmount] = newFriend;

	delete[] pOldFriend;
}

void FriendSet::operator=(const FriendSet& other)
{
	if (pFriend != NULL)
	{
		delete[] pFriend;
	}
	amount = other.amount;
	pFriend = new int[amount];
	for (int i = 0; i < amount; ++i)
	{
		pFriend[i] = other.pFriend[i];
	}
}

const int& FriendSet::operator[](int idx) const
{
	return pFriend[idx];
}

int & FriendSet::operator[](int idx)
{
	return pFriend[idx];
}
