#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main()
{
	string input;
	int sqaureCodeLength, inputSize;

	while (cin >> input)
	{
		inputSize = input.size();
		sqaureCodeLength = ceil(sqrt(inputSize));
		for (int i = 0; i < sqaureCodeLength; ++i)
		{
			int index = i;
			while (index < inputSize)
			{
				cout << input[index];
				index += sqaureCodeLength;
			}
			cout << endl;
		}
	}

	return 0;
}