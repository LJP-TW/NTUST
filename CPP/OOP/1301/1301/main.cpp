#include "templateBS.hpp"
#define ARRAY_SIZE 50

int main()
{
	int a[ARRAY_SIZE];
	const int finalIndex = ARRAY_SIZE - 1;
	int i;
	for (i = 0; i < ARRAY_SIZE; i++)
		a[i] = 3 * i;
	cout << "Array contains:\n";
	for (i = 0; i < ARRAY_SIZE; i++)
		cout << a[i] << " ";
	cout << endl;
	int key, location;
	bool found;
	cout << "Enter number to be located: ";
	cin >> key;
	cout << "\nTesting Template Iterative Binary Search\n";
	ItrSearch(a, 0, finalIndex, key, found, location);
	if (found)
		cout << key << " is in index location "
		<< location << endl;
	else
		cout << key << " is not in the array." << endl;
	cout << "\nTesting Template Recursive Binary Search\n";
	recBinSrch(a, 0, finalIndex, key, found, location);
	if (found)
		cout << key << " is in index location "
		<< location << endl;
	else
		cout << key << " is not in the array." << endl;

	system("pause");
	return 0;
}
