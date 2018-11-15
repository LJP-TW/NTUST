#include <iostream>
#include <vector>

using namespace std;

struct customer {
	int arrival;
	int service;
	int allow_wait;
	bool mark; // True: 有服務到, False: 沒服務到
	int departure; // 離開的時間
};

vector<customer> customers;

/*
會接受使用者輸入, 並儲存在 customers 裡面
*/
void input();

void output();

int main()
{
	int time = 0;
	int n; // Client 總共幾個
	int m = 0; // 已經處理完幾個 Client
	customer* sit = NULL; // 會指到 正在被服務的人, 若值為 NULL 表示現在沒有服務誰
	vector<customer*> queue; // 排隊的地方

    // Input
	input();

	n = customers.size();

	// Time 迴圈
	while (m < n)
	{
		// 有人到店的處裡 開始
		for (int i = 0; i < customers.size(); ++i)
		{
			if (customers[i].arrival == time)
			{
				// 如果沒在服務人, 就直接服務到店的人
				if (sit == NULL)
				{
					sit = &customers[i];
				}

				// 如果有在服務人:
				else
				{
					int wait_time = 0;

					wait_time += sit->service;
					for (int i = 0; i < queue.size(); ++i)
					{
						wait_time += queue[i]->service;
					}

					//   剛到店的人是否願意等
					if (customers[i].allow_wait >= wait_time)
					{
						//     如果願意:
						//       排隊
						queue.push_back(&customers[i]);
					}
					else
					{
						//     如果不願意:
						//       詢問前面的人是否可以插隊(前面不一定有人)
						if (queue.size() > 0)
						{
							int wait_time_2 = wait_time - queue[queue.size() - 1]->service + customers[i].service;

							if (queue[queue.size() - 1]->allow_wait >= wait_time_2)
							{
								int wait_time_3 = wait_time - queue[queue.size() - 1]->service;
								// 如果可以:
								//  如果真的插隊了, 剛到店的人是否就真的等得到呢
								if (customers[i].allow_wait >= wait_time_3)
								{
									//	 如果可以:
									//	  插隊啦 感恩
									queue.push_back(queue[queue.size() - 1]);
									queue[queue.size() - 2] = &customers[i];
								}
								else
								{
									//         如果不行:
									//           走人
									customers[i].mark = false;
									++m;
								}
							}
							else
							{
								//         如果不行:
								//           走人
								customers[i].mark = false;
								++m;
							}
						}
						else
						{
							//         如果不行:
							//           走人
							customers[i].mark = false;
							++m;
						}
					}
				}
			}
		}
		// 有人到店的處裡 結束

		// 過了一秒
		++time;

		// 被服務的人的服務時間減一
		if (sit != NULL)
		{
			--sit->service;
		}

		// 如果服務完畢
		if (sit != NULL && sit->service == 0)
		{
			// 紀錄一下離開時間, 並打上標記
			sit->mark = true;
			sit->departure = time;
			++m;

			// 若有人在排隊, 則請第一個人坐上位置
			if (queue.size() != 0)
			{
				// 請排隊列中的第一個人坐上位置
				sit = queue[0];

				// 排隊列後面的人 往前排
				for (int i = 1; i < queue.size(); ++i)
				{
					queue[i - 1] = queue[i];
				}
				queue.pop_back();
			}
			// 若沒有人在排隊, 把座位清空
			else
			{
				sit = NULL;
			}
		}

		// 在排隊中的每個人願意等待的時間都減一
		for (int i = 0; i < queue.size(); ++i)
		{
			--queue[i]->allow_wait;
		}
	}

	// Output
	output();

	int temp;
	cin >> temp;
}

void input()
{
	int n, arrival, service, allow_wait;
	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		cin >> arrival >> service >> allow_wait;
		customers.push_back({ arrival, service, allow_wait, false, 0 });
	}
}

void output()
{
	cout << "             Served\tDeparture" << endl;
	for (int i = 0; i < customers.size(); ++i)
	{
		if (customers[i].mark)
		{
			cout << "Client [" << i << "] : Yes\t" << customers[i].departure << endl;
		}
		else
		{
			cout << "Client [" << i << "] : No" << endl;
		}
	}
}