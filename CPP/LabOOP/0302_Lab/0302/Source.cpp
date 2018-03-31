#include <iostream>

using namespace std;

int N, nowN;

void Differential(int* coefficients);
void Differential(int* coefficients, int times);
void Print(int* coefficients);

void Differential(int* coefficients)
{
	if (nowN == 1)
	{
		coefficients[0] = 0;
		return;
	}

	for (int i = 1; i < nowN; ++i)
	{
		coefficients[i - 1] = coefficients[i] * i;
	}
	--nowN;
}

void Differential(int* coefficients, int times)
{
	int* tCoefficients = new int[nowN];

	for (int i = 0; i < nowN; ++i)
	{
		tCoefficients[i] = coefficients[i];
	}

	for (int i = 0; i < times; ++i)
	{
		Differential(tCoefficients);
	}
	Print(tCoefficients);
	nowN = N;

	delete[] tCoefficients;
}

void Print(int* coefficients)
{
	cout << coefficients[nowN - 1];
	for (int i = nowN - 2; i >= 0; --i)
	{
		cout << " " << coefficients[i];
	}
	cout << endl;
}

int main()
{
	int times;
	int* coefficients;

	while (cin >> N >> times)
	{
		nowN = N;

		coefficients = new int[N];

		for (int i = N - 1; i >= 0; --i)
		{
			cin >> coefficients[i];
		}

		// method 1 differential
		Differential(coefficients, times);

		// method 2 differential
		for (int i = 0; i < times; i++)
		{
			Differential(coefficients);
			Print(coefficients);
		}

		delete[] coefficients;
	}

	return 0;
}