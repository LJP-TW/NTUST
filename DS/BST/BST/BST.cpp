#include "BST.h"

BST::BST() : first(NULL)
{
}

bool BST::insertNode(int key, string data)
{
	// 如果是第一個 Node
	if (first == NULL)
	{
		first = new Node<int, string>(NULL, NULL, NULL, key, data);
		return true;
	}
	
	// 尋找放置 Node 的正確位置
	Node<int, string>* parent; // 新 Node 的 parent
	Node<int, string>* lookahead; // 先前往下一個 Node 尋找是否可以放新 Node
	Node<int, string>* newNode;

	parent = first;
	lookahead = first;

	while (lookahead != NULL)
	{
		parent = lookahead;
		if (key > parent->key)
		{
			lookahead = parent->r_child;
		}
		else if (key == parent->key)
		{
			// key 重複
			return false;
		}
		else if (key < parent->key)
		{
			lookahead = parent->l_child;
		}
	}

	newNode = new Node<int, string>(parent, NULL, NULL, key, data);

	if (key < parent->key)
	{
		parent->l_child = newNode;
	}
	else
	{
		parent->r_child = newNode;
	}

	return true;
}

bool BST::deleteNode(int key)
{
	// 如果根本沒有任何 Node
	if (first == NULL)
	{
		return false;
	}

	// 尋找 Node
	Node<int, string>* parent = first;
	Node<int, string>* current = first;

	while (current != NULL && key != current->key)
	{
		parent = current;
		if (key < current->key)
		{
			current = current->l_child;
		}
		else
		{
			current = current->r_child;
		}
	}

	// 若找不到
	if (current == NULL)
	{
		return false;
	}
		
	if (current->l_child == NULL && current->r_child == NULL)
	{
		// 如果此 Node 底下沒 Child
		// 就直接砍掉
		if (current->key < parent->key)
		{
			parent->l_child = NULL;
		}
		else
		{
			parent->r_child = NULL;
		}

		delete current;
	}
	else if (current->l_child && current->r_child)
	{
		// 如果此 Node 底下有兩個 Child
		//   拿 r_child 為 root 的子樹中最小的 Node 替補此被刪除的 Node
		//   再把r_child 為 root 的子樹中最小的 Node 砍掉
		//     因為是最小的 Node, 此 Node 只會分有無 r_child 的兩種 case

		Node<int, string>* r_parent; // r_child 為 root 的子樹中最小的 Node 的 parent
		Node<int, string>* r_lookahead; // 先前往下一個 Node 尋找是否為最小的 Node

		r_parent = current->r_child;
		r_lookahead = current->r_child;

		while (r_lookahead->l_child != NULL)
		{
			r_parent = r_lookahead;
			r_lookahead = r_parent->l_child;
		}

		// 拿 r_child 為 root 的子樹中最小的 Node 替補此被刪除的 Node
		
	}
	else
	{
		// 如果此 Node 底下有一個 Child
		if (current->key < parent->key)
		{
			parent->l_child = current->l_child != NULL ? current->l_child : current->r_child;
		}
		else
		{
			parent->r_child = current->l_child != NULL ? current->l_child : current->r_child;
		}

		delete current;
	}
}

Node<int, string>* BST::get(int key)
{
	// 如果根本沒有任何 Node
	if (first == NULL)
	{
		return NULL;
	}

	Node<int, string>* current = first;

	while (current != NULL)
	{
		if (key == current->key)
		{
			return current;
		}

		if (key < current->key)
		{
			current = current->l_child;
		}
		else
		{
			current = current->r_child;
		}
	}
	
	// 若找不到
	return NULL;
}

void BST::printTree()
{
}
