#ifndef GENERALIZEDLIST_3H
#define GENERALIZEDLIST_3H

#include <exception>
#include <vector>

#define VAR_NUM 3

using namespace std;

// Exception for retCoeff
struct PolyListRetCoeffException : public exception
{
	const char* errorMsg() const throw()
	{
		return "no match.";
	}
};

enum Type
{
	VAR, // �ܼ�
	PTR, // ����
	COE // �Y��
};

struct PolyListNode
{
	PolyListNode *next; // ���V�U�@�ӥN��P�ܼơB���P�������`�I
	int exp; // ����
	Type type;
	union {
		PolyListNode *down; // ���V�U�@���ܼƪ�����
		int coef; // �Y��
		int var; // �ĴX���ܼ�
	};
};

class PolyList3
{
public:
	/* Constructor */
	PolyList3();
	~PolyList3();

	/* Mutator */
	/*
	Create a polynode which is x^(ex)y^(ey)z^(ez)
	�Y������, �h�л\�¦��� polynode
	*/
	void create(int coef, int *e);

	/*
	Multiply polyno by x^(ex)y^(ey)z^(ez)
	*/
	void mulf(int *e);

	/* Accessor */
	/*
	Return the coeffieient of x^(ex)y^(ey)z^(ez)
	If there is no match, throw PolyListRetCoeffException
	*/
	int retCoeff(int *e) throw (PolyListRetCoeffException);

private:
	PolyListNode *polyno;
};

#endif