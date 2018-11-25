#ifndef GENERALIZEDLIST_H
#define GENERALIZEDLIST_H

#include <exception>
#include <vector>
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
	};
};

class PolyList
{
public:
	/* Constructor */
	PolyList();

	/* Mutator */
	/*
		Add a polynode which is x^(ex)y^(ey)z^(ez)...
	*/
	void Add(int args...);

	/*
		Multiply polyno by x^(ex)y^(ey)z^(ez)...
	*/
	void Mulf(int args...);

	/* Accessor */
	/*
		Return the coeffieient of x^(ex)y^(ey)z^(ez)...
		If there is no match, throw PolyListRetCoeffException
	*/
	int retCoeff(int args...) throw (PolyListRetCoeffException);

protected:
	/* Helper * /
	/*
		�N Parameter Pack �ন vector<int>
	*/
	vector<int> ppToInts(int ints...);
	void ppToIntsProcessing(vector<int>& v, int T);
	void ppToIntsProcessing(vector<int>& v, int T, int ints...);

private:
	PolyListNode *polyno;
	int polyNum; // �ܼƼƶq
};

#endif