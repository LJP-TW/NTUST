// Name: 張書銘
// Date: Apr. 26, 2018
// Last Update: Apr. 26, 2018
// Problem statement: 我的朋友很少
#ifndef FRIENDSET_H
#define FRIENDSET_H

class FriendSet 
{
public:
	FriendSet();
	FriendSet(int);
	FriendSet(const FriendSet&);
	~FriendSet();

	bool findFriend(int);
	int size();

	void operator+=(FriendSet);
	void operator+=(int);
	void operator=(const FriendSet&);
	const int& operator[](int) const;
	int& operator[](int);

private:
	// Pointer to all friend in this set
	int *pFriend;
	// The amount of friends in this set
	int amount;
};

#endif