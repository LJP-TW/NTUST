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
	VAR, // 跑计
	PTR, // 夹
	COE // 玒计
};

struct PolyListNode 
{
	PolyListNode *next; // 跑计ぃ经Ω竊翴
	int exp; // 经Ω
	Type type;
	union {
		PolyListNode *down; // 跑计夹
		int coef; // 玒计
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
		盢 Parameter Pack 锣Θ vector<int>
	*/
	vector<int> ppToInts(int ints...);
	void ppToIntsProcessing(vector<int>& v, int T);
	void ppToIntsProcessing(vector<int>& v, int T, int ints...);

private:
	PolyListNode *polyno;
	int polyNum; // 跑计计秖
};

#endif