//#define CPP_VERSION

#ifdef CPP_VERSION
#include <iostream>
#include <string>
#include <vector>
using namespace std;

//#define MING

string words;
int **WordsPicture;

// 此 function 用來找字串 words 從 start 到 end 中
// LPS 的長度
// 再把 LPS 的長度存到 WordsPicture[start][end]
void LPS(int start, int end)
{
	// 如果 WordsPicture[start][end] 已經算過了
	// 就不要再算一次了
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

// 要根據圖表輸出
// 1. 回文的長度
// 2. 回文本身
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
	vector <string> wordsbuf;////輸入儲存的vector
	while (cin >> N)//輸入數字
	{
		for (int i = 0; i < N; i++)//儲存字串
		{
			cin >> words;
			// 建立 words.length() x words.length() 大小的圖表
			WordsPicture = new int*[words.length()];
			for (int i = 0; i < words.length(); i++)
			{
				WordsPicture[i] = new int[words.length()];

				//初始化
				for (int j = 0; j < words.length(); j++)
				{
					WordsPicture[i][j] = -1;
				}
			}

			// 算圖表
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

			// 根據圖表去產生輸出 ----------------------------------------------------
			LPS_Output();

			// Free 掉圖表
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