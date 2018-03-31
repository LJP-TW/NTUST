// Name: B10615025 ±i®Ñ»Ê
// Date: Mar. 22, 2018
// Last Update: Mar. 22, 2018
// Problem statement: ¡GUnspoken RR Rules
#include <iostream>
#include <string>
#include <vector>
#include "FakeRand.h"
//#define DEBUG

using namespace std;

struct Player
{
	string name;
	int level;
	int startTime;
	int playingTime;
};

struct Store
{
	Player* a;
	Player* b;
	vector<Player *> queue;
	int straightWin;
	bool isGameStart;
	int gameEndTime;
};

// Intent: To simulate if target player defeats his opponent.
// Pre: Pass target's level and opponent's level.
// Post: Return true if target wins, false if his opponent wins.
// targetLv will be nerf
bool Win(const int &targetLv, const int &opponentLv) {
	double rate = pow(2, (targetLv - 1) - opponentLv);
	return rand() / (RAND_MAX + 1.0) < rate / (rate + 1);
}

int main()
{
	// Player Mount
	int n;
	vector<Player> players;
	Store store;

	while (cin >> n)
	{
		int time = 0;

		// Initial
		players.clear();
		store.a = nullptr;
		store.b = nullptr;
		store.queue.clear();
		store.straightWin = 0;
		store.isGameStart = false;
		store.gameEndTime = 0;

		// Receive Player Info
		for (int i = 0; i < n; ++i)
		{
			Player tempPlayer;
			cin >> tempPlayer.name >> tempPlayer.level >> tempPlayer.startTime >> tempPlayer.playingTime;
			players.push_back(tempPlayer);
		}

		// Main Loop
		while (true)
		{
			// If there is only a player, break this loop;
			if (n == 1)
			{
				break;
			}


#ifdef DEBUG
			if (store.a != nullptr && store.b != nullptr)
			{
				cout << "Before " << time << " ";
				cout << store.a->name << " " << store.a->playingTime << " vs " << store.b->name << " " << store.b->playingTime << endl;
			}
#endif

			// whether need to output
			bool outputFlag = false;
			string field1, field2, field3;

			// Event : Join
			for (int i = 0; i < players.size(); ++i)
			{
				if (players[i].startTime == time)
				{
					if (store.a == nullptr)
					{
						store.a = &players[i];
					}
					else if (store.b == nullptr)
					{
						store.b = &players[i];
					}
					else
					{
						store.queue.push_back(&players[i]);
					}
					outputFlag = true;
				}
			}

			// Event : GameOver
			if (store.isGameStart && store.gameEndTime == time)
			{
				store.a->playingTime -= 5;
				store.b->playingTime -= 5;

				if (Win(store.a->level, store.b->level) && store.straightWin < 4)
				{
					store.straightWin += 1;
					if (!store.queue.empty())
					{
						store.queue.push_back(store.b);
						store.b = nullptr;
					}
				}
				else
				{
					store.straightWin = 1;
					if (store.queue.empty())
					{
						swap(store.a, store.b);
					}
					else
					{
						store.queue.push_back(store.a);
						store.a = store.b;
						store.b = nullptr;
					}
				}

				store.isGameStart = false;
				outputFlag = true;
			}

			// Event : Quit
			if (store.isGameStart == false)
			{
				// Check queue
				for (int i = 0; i < store.queue.size(); ++i)
				{
					if (store.queue[i]->playingTime <= 0)
					{
						store.queue.erase(store.queue.begin() + i);
						n -= 1;
					}
				}
				// Check player
				if (store.a != nullptr && store.a->playingTime <= 0)
				{
					store.a = nullptr;
					n -= 1;
				}
				if (store.b != nullptr && store.b->playingTime <= 0)
				{
					store.b = nullptr;
					n -= 1;
				}
			}

			// Event : GameStart
			if (store.a == nullptr && !store.queue.empty())
			{
				store.a = store.queue[0];
				store.queue.erase(store.queue.begin());
			}
			else if (store.b == nullptr && !store.queue.empty())
			{
				store.b = store.queue[0];
				store.queue.erase(store.queue.begin());
			}

			if (store.isGameStart == false && store.a != nullptr && store.b != nullptr)
			{
				store.isGameStart = true;
				store.gameEndTime = time + 5;
			}

			// Output
			if (outputFlag)
			{
				if (store.a == nullptr)
				{
					field1 = "none";
				}
				else
				{
					field1 = store.a->name;
					field1 += " lv";
					field1 += to_string(store.a->level);
				}

				if (store.b == nullptr)
				{
					field2 = "none";
				}
				else
				{
					field2 = store.b->name;
					field2 += " lv";
					field2 += to_string(store.b->level);
				}

				field3 = "";
				for (int i = 0; i < store.queue.size(); ++i)
				{
					field3 += " ";
					field3 += store.queue[i]->name;
				}

				cout << time << ": " << field1 << " vs. " << field2 << " |" << field3 << endl;
			}

#ifdef DEBUG
			if (store.a != nullptr && store.b != nullptr)
			{
				cout << "After ";
				cout << store.a->name << " " << store.a->playingTime << " vs " << store.b->name << " " << store.b->playingTime << endl;
			}
#endif

			// Loop Finish
			++time;
		}
	}

	return 0;
}