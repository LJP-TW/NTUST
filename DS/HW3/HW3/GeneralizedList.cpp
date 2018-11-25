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

	// par[0] ��ܫY��
	// par[1] ��ܲ�1��������
	// par[2] ��ܲ�2��������
	// �H������
	// �Y�ثe poly ���Ʀh�� par ��������
	// �h par �᭱�S�]�w�쪺���w�]������ 0 ��
	// �Y�ثe poly ���Ƥ֩� par ��������
	// �h�|�W�� poly ����
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

	// par[0] ��ܲ�1��������
	// par[1] ��ܲ�2��������
	// par[2] ��ܲ�3��������
	// �H������
	// �Y�ثe poly ���Ʀh�� par ��������
	// �h par �᭱�S�]�w�쪺���w�]������ 0 ��
}

int PolyList::retCoeff(int args...) throw (PolyListRetCoeffException)
{
	vector<int> par = ppToInts(args); // parameter

	// par[0] ��ܲ�1��������
	// par[1] ��ܲ�2��������
	// par[2] ��ܲ�3��������
	// �H������
	// �Y�ثe poly ���Ʀh�� par ��������
	// �h par �᭱�S�]�w�쪺���w�]������ 0 ��

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