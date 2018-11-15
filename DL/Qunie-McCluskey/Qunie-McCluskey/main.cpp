#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <cmath>
#include <cstdlib>

using namespace std;

vector<string> G_OF; // Global Origin (Boolean) Function
vector<string> G_F; // Global (Minimized Boolean) Function
vector<string> G_D; // Global Don't care
vector<string> G_PI; // Prime Implicant
vector<string> G_Minterm; // Minterm of G_OF

vector<char> G_ilb;
char G_ob;

/*
	Get user input from file, 展開 Boolean Funciton 後 storing into G_OF, G_D.
	G_OF 跟 G_D 也都存到 G_F
*/
void input(char* filename);

/*
	Output data that project required into file.
*/
void output(char* filename);

/*
	Reduce boolean function.
	Param:
		vector<string> F: Boolean function that will be reduced.
*/
vector<string> reduce(vector<string> F);

/*
	Check if the difference between string a & b is just a bit.
	If true, return the position of the bit,
	else return -1.
*/
int isGrayCode(string a, string b);

/*
	Push element into F after checking there isn't a already existed element in F.
*/
void pushWithoutRepeated(vector<string>& F, string element);

/*
	expand terms into ints
*/
vector<int> stringToInts(string);

/*
	transfer i to string of length digit
*/
string intToString(int i, int digit);

/*
	Implement https://en.wikipedia.org/wiki/Petrick%27s_method
	Input: G_PI
	output: G_Minterm
*/
void petrick();

int main(int argc, char *argv[])
{
	// Input
	input(argv[1]);
	
	// 算 PI
	do {
		G_F = reduce(G_F);
	} while (G_F.size() > 0);

	// 選擇哪些Terms
	// Petrick's method
	petrick();

	// Output
	output(argv[2]);
}

vector<string> reduce(vector<string> F)
{
	bool* checked = new bool[F.size()];
	vector<string> newF;
	vector<vector<int>> groups; // group end location

	// Initial checked
	for (int i = 0; i < F.size(); ++i)
	{
		checked[i] = false;
	}

	// Initial groups
	for (int i = 0; i <= G_ilb.size(); ++i)
	{
		groups.push_back(vector<int>());
	}

	for (int i = 0; i < F.size(); ++i)
	{
		int count = 0;
		for (int j = 0; j < F[i].length(); ++j)
		{
			if (F[i][j] == '1')
			{
				++count;
			}
		}

		groups[count].push_back(i);
	}

	// Find pair between groups
	for (int g = 0; g < groups.size() - 1; ++g)
	{
		for (int i = 0; i < groups[g].size(); ++i)
		{
			for (int j = 0; j < groups[g + 1].size(); ++j)
			{
				int wdBit;
				if ((wdBit = isGrayCode(F[groups[g][i]], F[groups[g + 1][j]])) != -1)
				{
					// Replace with wildcard, pushing into newF after checking there is not a repeated element in newF, setting checked and flag
					checked[groups[g][i]] = true;
					checked[groups[g + 1][j]] = true;

					string temp = F[groups[g][i]];
					temp[wdBit] = '-';

					pushWithoutRepeated(newF, temp);
				}
			}
		}
	}

	// Push minterm
	for (int i = 0; i < F.size(); ++i)
	{
		if (!checked[i])
		{
			pushWithoutRepeated(G_PI, F[i]);
		}
	}

	delete[] checked;

	return newF;
}

void input(char* filename)
{
	ifstream file(filename);
	string line;
	int libNum;
	int max = -1;
	int pNum;

	// getline first
	while (getline(file, line))
	{
		istringstream iss(line);
		string buf;

		iss >> buf;

		if (buf == ".i")
		{
			iss >> libNum;
			max = pow(2, libNum);
		}
		else if (buf == ".o")
		{
			continue;
		}
		else if (buf == ".ilb")
		{
			char temp;
			for (int i = 0; i < libNum; ++i)
			{
				iss >> temp;
				G_ilb.push_back(temp);
			}
		}
		else if (buf == ".ob")
		{
			iss >> G_ob;
		}
		else if (buf == ".p")
		{
			if (max == -1)
			{
				exit(1);
			}

			bool* OFterms = new bool[max];
			bool* Dterms = new bool[max];

			for (int i = 0; i < max; ++i)
			{
				OFterms[i] = false;
				Dterms[i] = false;
			}

			iss >> pNum;

			for (int i = 0; i < pNum; ++i)
			{
				string lineP, // e.g. 01-0 -
					bfunc; // e.g. 01-0
				char value; // e.g. -
				vector<int> table;

				getline(file, lineP);

				istringstream tempIss(lineP);

				tempIss >> bfunc >> value;

				table = stringToInts(bfunc);

				for (int i = 0; i < table.size(); ++i)
				{
					if (value == '1')
					{
						OFterms[table[i]] = true;
					}
					else if (value == '-')
					{
						Dterms[table[i]] = true;
					}
				}				
			}

			// Set false to i-th item of Dterms when i-th item of OFterms is true
			for (int i = 0; i < max; ++i)
			{
				if (OFterms[i])
				{
					Dterms[i] = false;
				}
			}

			// Store into G_OF, G_F, G_D
			for (int i = 0; i < max; ++i)
			{
				if (OFterms[i])
				{
					G_OF.push_back(intToString(i, libNum));
					G_F.push_back(intToString(i, libNum));
				}
				else if (Dterms[i])
				{
					G_D.push_back(intToString(i, libNum));
					G_F.push_back(intToString(i, libNum));
				}
			}

			delete[] OFterms;
			delete[] Dterms;
		}
		else if (buf == ".e")
		{
			continue;
		}
	}

	file.close();
}

void output(char* filename)
{
	ofstream file(filename);
	int lit = 0;

	file << ".i " << G_ilb.size() << endl;
	file << ".o 1" << endl;
	file << ".ilb";

	for (int i = 0; i < G_ilb.size(); ++i)
	{
		file << ' ' << G_ilb[i];
	}
	file << endl;

	file << ".ob " << G_ob << endl;
	file << ".p " << G_Minterm.size() << endl;

	for (int i = 0; i < G_Minterm.size(); ++i)
	{
		file << G_Minterm[i] << " 1" << endl;
		for (int j = 0; j < G_Minterm[i].size(); ++j)
		{
			if (G_Minterm[i][j] != '-')
			{
				++lit;
			}
		}
	}

	file << ".e";

	file.close();

	cout << "Total number of terms: " << G_Minterm.size() << endl;
	cout << "Total number of literals: " << lit << endl;
}

string intToString(int i, int digit)
{
	string result = "", temp = "";

	while (i)
	{
		if (i % 2)
		{
			temp += '1';
		}
		else
		{
			temp += '0';
		}

		i /= 2;
	}

	for (int i = 0; i < (digit - temp.length()); ++i)
	{
		result += '0';
	}

	for (int i = temp.length() - 1; i >= 0; --i)
	{
		result += temp[i];
	}

	return result;
}

void pushWithoutRepeated(vector<string>& F, string element)
{
	if (std::find(F.begin(), F.end(), element) == F.end())
	{
		F.push_back(element);
	}
}

int isGrayCode(string a, string b)
{
	int diff = -1;

	if (a.size() != b.size())
	{
		// Error
		return -1;
	}

	for (int i = 0; i < a.size(); ++i)
	{
		if (a[i] != b[i])
		{
			if (diff != -1)
			{
				return -1;
			}
			diff = i;
		}
	}

	return diff;
}

vector<int> stringToInts(string a)
{
	vector<int> posStack;
	vector<int> result;

	string temp = a;
	int pos = 0;

	// Expand string
	while (posStack.size() != 0 || pos < a.length())
	{
		if (a[pos] == '-')
		{
			if (temp[pos] == '-' || temp[pos] == '1')
			{
				temp[pos] = '0';
				posStack.push_back(pos);
			}
			else
			{
				temp[pos] = '1';
			}
		}

		++pos;

		if (pos == a.length())
		{
			int num = 0;
			for (int i = 0; i < temp.length(); ++i)
			{
				num <<= 1;
				if (temp[i] == '1')
				{
					num += 1;
				}
			}
			result.push_back(num);
			
			if (posStack.size() > 0)
			{
				pos = posStack[posStack.size() - 1];
				posStack.pop_back();
			}
		}
	}

	return result;
}

void petrick()
{
	/*
	BC :
		class: vector<int>
		data : 1, 2
	AD + BC:
		class: vector<vector<int>>
		data : vector<int>, vector<int>
	(AD + BC)(E + F):
		class: vector<vector<vector<int>>>
		data : vector<vector<int>>, vector<vector<int>>
	*/
	vector<vector<vector<int>>> T;
	bool notSimplest = true;
	int min;

	// Initial T
	for (int i = 0; i < G_OF.size(); ++i)
	{
		T.push_back(vector<vector<int>>());

		for (int j = 0; j < G_PI.size(); ++j)
		{
			bool termInPI = true;
			for (int k = 0; k < G_PI[j].length(); ++k)
			{
				if (G_PI[j][k] != '-' && G_PI[j][k] != G_OF[i][k])
				{
					termInPI = false;
					break;
				}
			}

			if (termInPI)
			{
				T[T.size() - 1].push_back(vector<int>());
				T[T.size() - 1][T[T.size() - 1].size() - 1].push_back(j);
			}
		}
	}

	/*
	Simplify T with the following equivalences until T cannot be simplified:
		X+XY = X
		XX = X
	*/
	while (notSimplest)
	{
		// X + XY = X
		for (int i = 0; i < T.size(); ++i)
		{
			for (int j0 = 0; j0 < T[i].size(); ++j0)
			{
				for (int j1 = j0 + 1; j1 < T[i].size(); ++j1)
				{
					if (T[i][j0].size() > T[i][j1].size())
					{
						auto temp = T[i][j0];
						T[i][j0] = T[i][j1];
						T[i][j1] = temp;
					}

					bool contained = true;

					for (int k = 0; k < T[i][j0].size(); ++k)
					{
						if (std::find(T[i][j1].begin(), T[i][j1].end(), T[i][j0][k]) == T[i][j1].end())
						{
							contained = false;
							break;
						}
					}

					if (contained)
					{
						// Match equivalences:
						// T[i][j0] + T[i][j0] * T[i][j1] = T[i][j0]
						// Delete T[i][j1]
						for (int m = j1 + 1; m < T[i].size(); ++m)
						{
							T[i][m - 1] = T[i][m];
						}
						T[i].pop_back();
						--j1;
					}
				}
			}
		}

		// distributive law, preventing situation that making XX e.g. (X + ...)(X + ...) = XX + ...
		if (T.size() > 1)
		{
			bool isEven;

			// T[i - 1] = T[i - 1] * T[i]
			for (int i = 1; i < T.size(); i += 2)
			{
				vector<vector<int>> temp;
				for (int j0 = 0; j0 < T[i - 1].size(); ++j0)
				{
					for (int j1 = 0; j1 < T[i].size(); ++j1)
					{
						vector<int> tempTerm = T[i - 1][j0];

						for (int k = 0; k < T[i][j1].size(); ++k)
						{
							if (std::find(tempTerm.begin(), tempTerm.end(), T[i][j1][k]) == tempTerm.end())
							{
								tempTerm.push_back(T[i][j1][k]);
							}
						}

						temp.push_back(tempTerm);
					}
				}

				T[i - 1] = temp;
			}

			isEven = (T.size() % 2) ? false : true;

			// Delete T[i]
			for (int i = 2; i < T.size(); ++i)
			{
				for (int j = i; j < T.size(); ++j)
				{
					T[j - 1] = T[j];
				}
				T.pop_back();
			}
			if (isEven)
			{
				T.pop_back();
			}
		}
		else
		{
			notSimplest = false;
		}
	}

	/*
		挑項數最少的輸出
	*/
	min = 0;
	for (int i = 0; i < T[0].size(); ++i)
	{
		if (T[0][min].size() > T[0][i].size())
		{
			min = i;
		}
	}

	for (int i = 0; i < T[0][min].size(); ++i)
	{
		G_Minterm.push_back(G_PI[T[0][min][i]]);
	}
}