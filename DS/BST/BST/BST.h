#ifndef BST_H
#define BST_H

#include <iostream>

using namespace std;

template<class KEY, class DATA>
struct Node 
{
	Node(Node* parent, Node* l_child, Node* r_child, KEY key, DATA data) : parent(parent), l_child(l_child), r_child(r_child), key(key), data(data) {}
	Node* parent;
	Node* l_child;
	Node* r_child;
	KEY key;
	DATA data;
};

class BST 
{
public:
	/* Constructor*/
	BST();

	/* Mutator */
	// 回傳是否成功
	bool insertNode(int key, string data);
	bool deleteNode(int key);

	/* Accessor */
	Node<int, string>* get(int key);

protected:
	/* Debuger */
	void printTree();

private:
	Node<int, string>* first;
};

#endif