#include "GeneralizedList3.h"

PolyList3::PolyList3()
{
	this->polyno = new PolyListNode();
	this->polyno->next = NULL;
	this->polyno->type = VAR;
	this->polyno->var = 0;
}

PolyList3::~PolyList3()
{
	vector<PolyListNode*> varNodeStack;

	varNodeStack.push_back(this->polyno);

	while (varNodeStack.size() != 0)
	{
		PolyListNode *currentVarNode = varNodeStack[0];
		PolyListNode *currentNode = currentVarNode->next;

		varNodeStack.erase(varNodeStack.begin());

		while (currentNode != NULL)
		{
			PolyListNode *temp = currentNode;

			if (currentNode->type == PTR)
			{
				varNodeStack.push_back(currentNode->down);
			}

			currentNode = currentNode->next;
			delete temp;
		}

		delete currentVarNode;
	}
}

void PolyList3::create(int coef, int *e)
{	
	PolyListNode *lastNode = this->polyno, *currentNode = lastNode->next;
	int i = 0;

	if (coef == 0)
	{
		return;
	}

	// ���D�̫�@���ܼƪ��B�z
	for (; i < VAR_NUM - 1; ++i)
	{
		// �M�䦹 Node �b��
		// �U�� PTR Node �|�� exp �Ѥp�ƨ�j
		// �Y�S���� Node, �h���J�s�� Node �b�A�X���a��
		while (currentNode != NULL && currentNode->exp < e[i])
		{
			lastNode = currentNode;
			currentNode = currentNode->next;
		}

		if (currentNode == NULL)
		{
			lastNode->next = new PolyListNode();
			currentNode = lastNode->next;

			currentNode->next = NULL;
			currentNode->exp = e[i];
			currentNode->type = PTR;
			currentNode->down = new PolyListNode();

			lastNode = currentNode;
			currentNode = currentNode->down;

			currentNode->next = NULL;
			currentNode->type = VAR;
			currentNode->var = i + 1;

			lastNode = currentNode;
			currentNode = currentNode->next;
		}
		else if (currentNode->exp != e[i])
		{
			lastNode->next = new PolyListNode();

			lastNode = lastNode->next;

			lastNode->next = currentNode;
			lastNode->exp = e[i];
			lastNode->type = PTR;
			lastNode->down = new PolyListNode();

			currentNode = lastNode->down;
			
			currentNode->next = NULL;
			currentNode->type = VAR;
			currentNode->var = i + 1;

			lastNode = currentNode;
			currentNode = currentNode->next;
		}
		else
		{
			lastNode = currentNode;
			currentNode = currentNode->down;

			lastNode = currentNode;
			currentNode = currentNode->next;
		}
	}

	// ���̫�@���ܼƪ��B�z
	// �M�䦹 Node �b��
	// �U�� COE Node �|�� exp �Ѥp�ƨ�j
	// �Y�S���� Node, �h���J�s�� Node �b�A�X���a��
	while (currentNode != NULL && currentNode->exp < e[i])
	{
		lastNode = currentNode;
		currentNode = currentNode->next;
	}

	if (currentNode == NULL)
	{
		lastNode->next = new PolyListNode();
		currentNode = lastNode->next;

		currentNode->next = NULL;
		currentNode->exp = e[i];
		currentNode->type = COE;
		currentNode->coef = coef;
	}
	else if (currentNode->exp != e[0])
	{
		lastNode->next = new PolyListNode();

		lastNode = lastNode->next;

		lastNode->next = currentNode;
		lastNode->exp = e[i];
		lastNode->type = COE;
		lastNode->coef = coef;
	}
	else
	{
		currentNode->coef = coef;
	}
}

void PolyList3::mulf(int *e)
{
	vector<PolyListNode*> varNodeStack;
	
	varNodeStack.push_back(this->polyno);

	while (varNodeStack.size() != 0)
	{
		PolyListNode *currentVarNode = varNodeStack[0];
		PolyListNode *currentNode = currentVarNode->next;

		varNodeStack.erase(varNodeStack.begin());

		while (currentNode != NULL)
		{
			currentNode->exp += e[currentVarNode->var];
			if (currentNode->type == PTR)
			{
				varNodeStack.push_back(currentNode->down);
			}
			currentNode = currentNode->next;
		}
	}
}

int PolyList3::retCoeff(int *e) throw(PolyListRetCoeffException)
{
	PolyListNode *currentNode = this->polyno->next;

	for (int i = 0; i < VAR_NUM; ++i)
	{
		while (currentNode != NULL && currentNode->exp < e[i])
		{
			currentNode = currentNode->next;
		}

		if (currentNode == NULL || currentNode->exp > e[i])
		{
			throw PolyListRetCoeffException();
		}

		if (i != VAR_NUM - 1)
		{
			currentNode = currentNode->down->next;
		}
	}

	return currentNode->coef;
}
