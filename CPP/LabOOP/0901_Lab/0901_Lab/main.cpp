// Name: 張書銘
// Date: Apr. 26, 2018
// Last Update: Apr. 26, 2018
// Problem statement: 我的朋友很少
#include <iostream>
#include <map>
#include <vector>
#include "FriendSet.h"
//#define DEBUG

using namespace std;

int main()
{
	int n, m, q;
	map<int, FriendSet> friendSetsMap;

	while (cin >> n >> m >> q)
	{
		for (; m; --m)
		{
			int A, B;
			int idx;

			cin >> A >> B;

			// Does the FriendSet of A exist
			auto search = friendSetsMap.find(A);

			// If exist, check if B is in this set
			// Else, create a new friendSet
			if (search != friendSetsMap.end())
			{
				if (!friendSetsMap[A].findFriend(B))
				{
					friendSetsMap[A] += B;
				}
			}
			else
			{
				friendSetsMap[A] = FriendSet(B);
			}
			
			// Does the friendSet of B exist
			search = friendSetsMap.find(B);

			// If exist, check if A is in this set
			// Else, create a new friendSet
			if (search != friendSetsMap.end())
			{
				if (!friendSetsMap[B].findFriend(A))
				{
					friendSetsMap[B] += A;
				}
			}
			else
			{
				friendSetsMap[B] = FriendSet(A);
			}
		}

#ifdef DEBUG
		for (auto i : friendSetsMap)
		{
			cout << i.first << " Friend : " << endl;
			for (int j = 0; j < i.second.size(); ++j)
			{
				cout << i.second[j] << " ";
			}
			cout << endl;
		}
#endif

		for (; q; --q)
		{
			int A, B;
			bool isFriendFlag = false;
			int nowKey;
			vector<int> searchingList;
			vector<int> searchedList;
			
			cin >> A >> B;

			// Check if A, B are friends
			searchingList.push_back(A);
			while (searchingList.size())
			{
				bool foundFlag = false;
				nowKey = searchingList[0];
				searchingList.erase(searchingList.begin());

				// If find, yeah~~
				// Else, add the friends into searchingList if they are not't in searchedList
				for (int i = 0; i < friendSetsMap[nowKey].size(); ++i)
				{
					if (friendSetsMap[nowKey][i] == B)
					{
						isFriendFlag = true;
						foundFlag = true;
						break;
					}
					else
					{
						bool isSearched = false;
						for (int j = 0; j < searchedList.size(); ++j)
						{
							if (friendSetsMap[nowKey][i] == searchedList[j])
							{
								isSearched = true;
								break;
							}
						}

						if (!isSearched)
						{
							searchingList.push_back(friendSetsMap[nowKey][i]);
						}
					}
				}

				searchedList.push_back(nowKey);

				if (foundFlag)
				{
					break;
				}
			}

			searchedList.clear();
			searchingList.clear();

			if (isFriendFlag)
			{
				cout << ":)" << endl;
			}
			else
			{
				cout << ":(" << endl;
			}
		}

		friendSetsMap.clear();
	}

	return 0;
}