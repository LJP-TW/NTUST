#ifndef BST_H
#define BST_H

#include <iostream>
#include <exception>

using namespace std;

// Binary Search Tree

struct BstInsertException : public exception {
	const char* msg() const throw () {
		return "element already existed.";
	}
};

struct BstDeleteException : public exception {
	const char* msg() const throw () {
		return "no match.";
	}
};

struct BstRankException : public exception {
	const char* msg() const throw () {
		return "no match.";
	}
};

struct BstMinelementException : public exception {
	const char* msg() const throw () {
		return "no such element.";
	}
};

struct BstAvgException : public exception {
	const char* msg() const throw () {
		return "Out of range of rank.";
	}
};

struct Node {
	Node *parent;
	Node *left;
	Node *right;
	int data;
	int leftSize;

	Node(Node *p, Node *l, Node *r, int d, int k) :parent(p), left(l), right(r), data(d), leftSize(k) {}

};

class Bst {
public:
	Bst();

	// insert
	void ins(int);
	// delete
	void del(int);
	// search, checking if existed
	bool sea(int);
	// search int by rank
	int rank(int);
	int minelement(int);
	int avg(int, int);

private:
	Node *root;
};

#endif