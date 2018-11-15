#include <iostream>
#include <vector>

using namespace std;

struct customer {
	int arrival;
	int service;
	int allow_wait;
	bool mark; // True: ���A�Ȩ�, False: �S�A�Ȩ�
	int departure; // ���}���ɶ�
};

vector<customer> customers;

/*
�|�����ϥΪ̿�J, ���x�s�b customers �̭�
*/
void input();

void output();

int main()
{
	int time = 0;
	int n; // Client �`�@�X��
	int m = 0; // �w�g�B�z���X�� Client
	customer* sit = NULL; // �|���� ���b�Q�A�Ȫ��H, �Y�Ȭ� NULL ��ܲ{�b�S���A�Ƚ�
	vector<customer*> queue; // �ƶ����a��

    // Input
	input();

	n = customers.size();

	// Time �j��
	while (m < n)
	{
		// ���H�쩱���B�� �}�l
		for (int i = 0; i < customers.size(); ++i)
		{
			if (customers[i].arrival == time)
			{
				// �p�G�S�b�A�ȤH, �N�����A�Ȩ쩱���H
				if (sit == NULL)
				{
					sit = &customers[i];
				}

				// �p�G���b�A�ȤH:
				else
				{
					int wait_time = 0;

					wait_time += sit->service;
					for (int i = 0; i < queue.size(); ++i)
					{
						wait_time += queue[i]->service;
					}

					//   ��쩱���H�O�_�@�N��
					if (customers[i].allow_wait >= wait_time)
					{
						//     �p�G�@�N:
						//       �ƶ�
						queue.push_back(&customers[i]);
					}
					else
					{
						//     �p�G���@�N:
						//       �߰ݫe�����H�O�_�i�H����(�e�����@�w���H)
						if (queue.size() > 0)
						{
							int wait_time_2 = wait_time - queue[queue.size() - 1]->service + customers[i].service;

							if (queue[queue.size() - 1]->allow_wait >= wait_time_2)
							{
								int wait_time_3 = wait_time - queue[queue.size() - 1]->service;
								// �p�G�i�H:
								//  �p�G�u�������F, ��쩱���H�O�_�N�u�����o��O
								if (customers[i].allow_wait >= wait_time_3)
								{
									//	 �p�G�i�H:
									//	  ������ �P��
									queue.push_back(queue[queue.size() - 1]);
									queue[queue.size() - 2] = &customers[i];
								}
								else
								{
									//         �p�G����:
									//           ���H
									customers[i].mark = false;
									++m;
								}
							}
							else
							{
								//         �p�G����:
								//           ���H
								customers[i].mark = false;
								++m;
							}
						}
						else
						{
							//         �p�G����:
							//           ���H
							customers[i].mark = false;
							++m;
						}
					}
				}
			}
		}
		// ���H�쩱���B�� ����

		// �L�F�@��
		++time;

		// �Q�A�Ȫ��H���A�Ȯɶ���@
		if (sit != NULL)
		{
			--sit->service;
		}

		// �p�G�A�ȧ���
		if (sit != NULL && sit->service == 0)
		{
			// �����@�U���}�ɶ�, �å��W�аO
			sit->mark = true;
			sit->departure = time;
			++m;

			// �Y���H�b�ƶ�, �h�вĤ@�ӤH���W��m
			if (queue.size() != 0)
			{
				// �бƶ��C�����Ĥ@�ӤH���W��m
				sit = queue[0];

				// �ƶ��C�᭱���H ���e��
				for (int i = 1; i < queue.size(); ++i)
				{
					queue[i - 1] = queue[i];
				}
				queue.pop_back();
			}
			// �Y�S���H�b�ƶ�, ��y��M��
			else
			{
				sit = NULL;
			}
		}

		// �b�ƶ������C�ӤH�@�N���ݪ��ɶ�����@
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