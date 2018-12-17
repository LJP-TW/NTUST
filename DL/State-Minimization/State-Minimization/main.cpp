#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <cmath>
#include <vector>
// #define DEBUG

using namespace std;

struct _State
{
	string name;
	string output;
};

struct State
{
	int nextNum;
	map<int, _State> next;
};

struct DotState
{
	map<string, vector<string>> next;
};

/**
 * 00 S1 S2 0
 * 01 S1 S3 1
 * 10 S1 S4 1
 * 11 S1 S2 1
 * States["S1"]->next[2]->name = "S4"
 * States["S1"]->next[2]->output = 1
 */
map<string, State> States;
string initState;
int inNum, outNum;
int final_PNum, final_stateNum;

void readKiss(char *filename);
int binStrToInt(string binStr);

void reduceState();
void replaceState(string from, string to);

void writeKiss(char *filename);
string intToBinStr(int num);

void writeDot(char *filename);

void readKiss(char *filename)
{
	string line, cmd;
	bool isStart = false;
	int pNum;
	ifstream file(filename);

	while (getline(file, line))
	{
		istringstream iss(line);

		iss >> cmd;

		if (isStart)
		{
			if (cmd == ".i")
			{
				iss >> inNum;
			}
			else if (cmd == ".o")
			{
				iss >> outNum;
			}
			else if (cmd == ".p")
			{
				iss >> pNum;
			}
			else if (cmd == ".s")
			{
			}
			else if (cmd == ".r")
			{
				iss >> initState;
			}
			else if (cmd == ".end_kiss")
			{
				isStart = false;
			}
			else
			{
				if (pNum--) 
				{
					string s_input, s_state, s_nextState, s_output;

					s_input = cmd;
					iss >> s_state >> s_nextState >> s_output;

					States[s_state].nextNum = inNum;
					States[s_state].next[binStrToInt(s_input)].name = s_nextState;
					States[s_state].next[binStrToInt(s_input)].output = s_output;
				}
			}
		}
		else
		{
			if (cmd == ".start_kiss")
			{
				isStart = true;
			}
		}
	}
}

int binStrToInt(string binStr)
{
	int r = 0;
	for (int i = 0; i < (int)binStr.length(); ++i)
	{
		r <<= 1;
		if (binStr[i] == '1')
		{
			++r;
		}
	}
	return r;
}

#ifdef DEBUG
void debug_map() 
{
	for (auto i = States.begin(); i != States.end(); ++i)
	{
		cout << i->first << endl;
		cout << i->second.nextNum << endl;
		for (auto j = i->second.next.begin(); j != i->second.next.end(); ++j)
		{
			cout << j->first << ' ' << j->second.name << ' ' << j->second.output << endl;
		}
	}
}
#endif

void reduceState()
{
	bool isNotReduced = true;

	while (isNotReduced)
	{
		isNotReduced = false;
		for (auto i = States.begin(); i != States.end(); i++)
		{
			++final_stateNum;
			auto j = i;
			j++;
			for (; j != States.end(); j++)
			{
				bool same = true;

				// 檢查兩 States 是否一樣
				for (auto i_n = i->second.next.begin(), j_n = j->second.next.begin()
					; i_n != i->second.next.end() && j_n != j->second.next.end()
					; i_n++, j_n++)
				{
					if (i_n->first != j_n->first ||
						i_n->second.name != j_n->second.name ||
						i_n->second.output != j_n->second.output)
					{
						same = false;
						break;
					}
				}

				if (same)
				{
					// 若一樣則用比較前面的 State 取代後面的 State、刪除後面 State, 並且重新搜尋
					string from = j->first;
					string to = i->first;

					States.erase(from);

					replaceState(from, to);

					isNotReduced = true;
					break;
				}
			}

			if (isNotReduced)
			{
				break;
			}
		}
	}

	// 設定 final_PNum, final_stateNum
	final_PNum = 0;
	final_stateNum = 0;
	for (auto i = States.begin(); i != States.end(); i++)
	{
		++final_stateNum;
		for (auto j = i->second.next.begin(); j != i->second.next.end(); ++j)
		{
			++final_PNum;
		}
	}
}

void replaceState(string from, string to)
{
	for (auto i = States.begin(); i != States.end(); i++)
	{
		for (auto j = i->second.next.begin(); j != i->second.next.end(); j++)
		{
			if (j->second.name == from)
			{
				j->second.name = to;
			}
		}
	}
}

void writeKiss(char *filename)
{
	ofstream file;
	file.open(filename);
	file << ".start_kiss" << endl;
	file << ".i " << inNum << endl;
	file << ".o " << outNum << endl;
	file << ".p " << final_PNum << endl;
	file << ".s " << final_stateNum << endl;
	file << ".r " << initState << endl;

	for (auto i = States.begin(); i != States.end(); i++)
	{
		for (auto j = i->second.next.begin(); j != i->second.next.end(); ++j)
		{
			file << intToBinStr(j->first) << ' ' << i->first << ' ' << j->second.name << ' ' << j->second.output << endl;
		}
	}

	file << ".end_kiss" << endl;
}

string intToBinStr(int num)
{
	string r = "", result = "";

	while (num)
	{
		r += num % 2 ? '1' : '0';
		num /= 2;
	}

	for (int i = inNum - r.length(); i > 0; --i)
	{
		r += '0';
	}

	for (int i = r.length() - 1; i >= 0; --i)
	{
		result += r[i];
	}

	return result;
}

void writeDot(char *filename)
{
	// Initial DotStates
	map<string, DotState> DotStates;
	for (auto i = States.begin(); i != States.end(); i++)
	{
		for (auto j = i->second.next.begin(); j != i->second.next.end(); j++)
		{
			string s = intToBinStr(j->first) + '/' + j->second.output;
			DotStates[i->first].next[j->second.name].push_back(s);
		}
	}


	ofstream file;
	file.open(filename);
	file << "digraph STG {" << endl;
	file << "\trankdir=LR;" << endl;
	file << endl;
	file << "\tINIT [shape=point];" << endl;
	for (auto i = States.begin(); i != States.end(); i++)
	{
		file << '\t' << i->first << " [label=\"" << i->first << "\"];" << endl;
	}
	file << endl;
	file << "\tINIT -> " << initState << ';' << endl;
	for (auto i = DotStates.begin(); i != DotStates.end(); i++)
	{
		for (auto j = i->second.next.begin(); j != i->second.next.end(); j++)
		{
			file << '\t' << i->first << " -> " << j->first << " [label=\"" << j->second[0];
			for (int k = 1; k < j->second.size(); ++k)
			{
				file << ',' << j->second[k];
			}
			file << "\"];" << endl;
		}
	}
	file << "}" << endl;
}

int main(int argc, char *argv[])
{
	readKiss(argv[1]);

#ifdef DEBUG
	debug_map();
#endif

	reduceState();

	writeKiss(argv[2]);

	if (argc >= 4)
	{
		writeDot(argv[3]);
	}
}