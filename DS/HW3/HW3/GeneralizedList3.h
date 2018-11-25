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
	VAR, // 變數
	PTR, // 指標
	COE // 係數
};

struct PolyListNode
{
	PolyListNode *next; // 指向下一個代表同變數、不同冪次的節點
	int exp; // 冪次
	Type type;
	union {
		PolyListNode *down; // 指向下一個變數的指標
		int coef; // 係數
		int var; // 第幾個變數
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
	若有重複, 則覆蓋舊有的 polynode
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