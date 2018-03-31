#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	string sInput;
	vector<unsigned long long int> oldInput;
	vector<unsigned long long int> newInput;
	int size;

	// Handle Input: Finding first non-zero bit
	while (cin >> sInput)
	{
		oldInput.clear();
		newInput.clear();

		while (sInput[0] == '0')
		{
			sInput.erase(0, 1);
		}
		size = sInput.size();

		if (size == 0)
		{
			sInput = "0";
			size = 1;
		}

		for (int i = 0; i < size; ++i)
		{
			oldInput.push_back(sInput[i] - '0');
		}

		// Main Computation
		while (oldInput.size() != 1)
		{
			for (int i = 1; i < oldInput.size(); ++i)
			{
				newInput.push_back(oldInput[i] + oldInput[i - 1]);
			}
			oldInput = newInput;
			newInput.clear();
		}

		cout << oldInput[0] << endl;
	}

	return 0;
}