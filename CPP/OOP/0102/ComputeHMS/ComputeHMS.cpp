#include <iostream>

using namespace std;

int main()
{
	long long sec = 0, min = 0, hr = 0;

	while (cin >> sec)
	{
		min = sec / 60;
		sec %= 60;

		hr = min / 60;
		min %= 60;

		cout << hr << " hours " << min << " minutes and " << sec << " seconds" << endl;
	}

	return 0;
}