// Name: B10615025 ±i®Ñ»Ê
// Date: Mar. 22, 2018
// Last Update: Mar. 22, 2018
// Problem statement: Maximize Pulse
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// Custom signal Struct
struct signalStruct
{
	string signal;
	double ratio; // 1's bits / all bits
};

// Custom Sorting Function
bool sortFunction(signalStruct a, signalStruct b)
{
	return a.ratio > b.ratio;
}

int main()
{
	int n;
	vector<signalStruct> signals;
	while (cin >> n)
	{
		string combineString = "";
		int pulse = 0;
		signalStruct tempSignal;
		tempSignal.ratio = 0;
	
		for (int i = 0; i < n; ++i)
		{
			cin >> tempSignal.signal;
			signals.push_back(tempSignal);
		}
	
		// Calculate ratio of every signal
		for (int i = 0; i < signals.size(); ++i)
		{
			int bits1 = 0;
	
			for (int j = 0; j < signals[i].signal.size(); ++j)
			{
				if (signals[i].signal[j] == '1')
				{
					++bits1;
				}
			}
	
			signals[i].ratio = (double)bits1 / signals[i].signal.size();
		}
	
		// Sorting by ratio
		sort(signals.begin(), signals.end(), sortFunction);
	
		// Combine all string ordered by ratio
		for (int i = 0; i < signals.size(); ++i)
		{
			combineString += signals[i].signal;
		}

		// Calculate the pulses
		for (int i = 0; i < combineString.size(); ++i)
		{
			if (combineString[i] == '1')
			{
				for (int j = i + 1; j < combineString.size(); ++j)
				{
					if (combineString[j] == '0')
					{
						++pulse;
					}
				}
			}
		}

		// Output
		cout << pulse << endl;

		signals.clear();
	}

	return 0;
}
