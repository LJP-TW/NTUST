#include "GeneralizedList.h"

PolyList::PolyList()
{
	polyno = new PolyListNode();
	polyno->next = new PolyListNode();
	polyno->exp = 0;
	polyno->type = VAR;

	polyno->next->next = NULL;
	polyno->next->exp = 0;
	polyno->next->type = COE;
	polyno->next->coef = 0;

	polyNum = 0;
}

void PolyList::Add(int args...)
{
	vector<int> par = ppToInts(args); // parameter
	PolyListNode *lastNode = polyno, *currentNode = polyno->next;

	// par[0] 表示係數
	// par[1] 表示第1項的冪次
	// par[2] 表示第2項的冪次
	// 以此類推
	// 若目前 poly 項數多於 par 給的項數
	// 則 par 後面沒設定到的項預設為冪次 0 次
	// 若目前 poly 項數少於 par 給的項數
	// 則會增長 poly 項數
	if(par.size() - 1 < polyNum)
	{
		for (int i = 0; i < polyNum - (par.size() - 1); ++i)
		{
			par.push_back(0);
		}
	}

	for (int i = 1; i < par.size(); ++i)
	{
		bool notFound = true;
		while (notFound)
		{
		}
	}
}

void PolyList::Mulf(int args...)
{
	vector<int> par = ppToInts(args); // parameter

	// par[0] 表示第1項的冪次
	// par[1] 表示第2項的冪次
	// par[2] 表示第3項的冪次
	// 以此類推
	// 若目前 poly 項數多於 par 給的項數
	// 則 par 後面沒設定到的項預設為冪次 0 次
}

int PolyList::retCoeff(int args...) throw (PolyListRetCoeffException)
{
	vector<int> par = ppToInts(args); // parameter

	// par[0] 表示第1項的冪次
	// par[1] 表示第2項的冪次
	// par[2] 表示第3項的冪次
	// 以此類推
	// 若目前 poly 項數多於 par 給的項數
	// 則 par 後面沒設定到的項預設為冪次 0 次

	return 0;
}

vector<int> PolyList::ppToInts(int ints...)
{
	vector<int> result;
	ppToIntsProcessing(result, ints);
	return result;
}

void PolyList::ppToIntsProcessing(vector<int>& v, int T)
{
	v.push_back(T);
}

void PolyList::ppToIntsProcessing(vector<int>& v, int T, int ints...)
{
	v.push_back(T);
	ppToIntsProcessing(v, ints);
}