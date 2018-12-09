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

struct Node {
	Node *parent;
	Node *left;
	Node *right;
	int data;
	int rank;

	Node(Node *p, Node *l, Node *r, int d, int k) :parent(p), left(l), right(r), data(d), rank(k) {}

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

private:
	Node *root;
};

#endif