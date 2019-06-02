//#define CPP_VERSION

#ifdef CPP_VERSION
#include <iostream>
#include <string>
#include <vector>
using namespace std;

//#define MING

string words;
int **WordsPicture;

// �� function �Ψӧ�r�� words �q start �� end ��
// LPS ������
// �A�� LPS �����צs�� WordsPicture[start][end]
void LPS(int start, int end)
{
	// �p�G WordsPicture[start][end] �w�g��L�F
	// �N���n�A��@���F
	if (WordsPicture[start][end] != -1)
	{
		return;
	}

	if (start == end)
	{
		WordsPicture[start][end] = 1;
	}
	else if (start + 1 == end && words[start] == words[end])
	{
		WordsPicture[start][end] = 2;
	}
	else if (words[start] == words[end])
	{
		LPS(start + 1, end - 1);
		WordsPicture[start][end] = WordsPicture[start + 1][end - 1] + 2;
	}
	else
	{
		LPS(start, end - 1);
		LPS(start + 1, end);
		if (WordsPicture[start][end - 1] >= WordsPicture[start + 1][end])
		{
			WordsPicture[start][end] = WordsPicture[start][end - 1];
		}
		else
		{
			WordsPicture[start][end] = WordsPicture[start + 1][end];
		}
	}
}

// �n�ھڹϪ��X
// 1. �^�媺����
// 2. �^�奻��
void LPS_Output()
{
	cout << WordsPicture[0][words.length() - 1] << "\n";
	int s = 0;
	int e = words.length() - 1;
	string output = "";
	string temp = "";

	while (1)
	{
		if (WordsPicture[s][e] == 1)
		{
			output += words[s];
			break;
		}
		else if (s + 1 == e && WordsPicture[s][e] == 2)
		{
			output += words[s];
			output += words[s];
			break;
		}
		else if (WordsPicture[s + 1][e - 1] == WordsPicture[s][e] - 2 && words[s] == words[e])
		{
			output += words[s];
			temp += words[s];

			s += 1;
			e -= 1;
		}
		else if (WordsPicture[s][e - 1] == WordsPicture[s][e])
		{
			e -= 1;
		}
		else if (WordsPicture[s + 1][e] == WordsPicture[s][e])
		{
			s += 1;
		}
		else
		{
			s += 1;
			e -= 1;
		}
	}
	for (int i = temp.length() - 1; i >= 0; i--)
	{
		output += temp[i];
	}

	cout << output << "\n";
}

int main()
{
	int N;
	string max_result;
	string temp_result;
	string len;
	vector <string> wordsbuf;////��J�x�s��vector
	while (cin >> N)//��J�Ʀr
	{
		for (int i = 0; i < N; i++)//�x�s�r��
		{
			cin >> words;
			// �إ� words.length() x words.length() �j�p���Ϫ�
			WordsPicture = new int*[words.length()];
			for (int i = 0; i < words.length(); i++)
			{
				WordsPicture[i] = new int[words.length()];

				//��l��
				for (int j = 0; j < words.length(); j++)
				{
					WordsPicture[i][j] = -1;
				}
			}

			// ��Ϫ�
			LPS(0, words.length() - 1);

#ifdef MING
			for (int i = 0; i < words.length(); i++)
			{
				for (int j = 0; j < words.length(); j++)
				{
					cout << WordsPicture[i][j] << " ";
				}
				cout << "\n";
			}
#endif

			// �ھڹϪ�h���Ϳ�X ----------------------------------------------------
			LPS_Output();

			// Free ���Ϫ�
			for (int i = 0; i < words.length(); i++)
			{
				delete[] WordsPicture[i];
			}
			delete[] WordsPicture;
		}
	}
	return 0;
}

#endif