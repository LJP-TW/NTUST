#include "BST.h"

BST::BST() : first(NULL)
{
}

bool BST::insertNode(int key, string data)
{
	// �p�G�O�Ĥ@�� Node
	if (first == NULL)
	{
		first = new Node<int, string>(NULL, NULL, NULL, key, data);
		return true;
	}
	
	// �M���m Node �����T��m
	Node<int, string>* parent; // �s Node �� parent
	Node<int, string>* lookahead; // ���e���U�@�� Node �M��O�_�i�H��s Node
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
			// key ����
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
	// �p�G�ڥ��S������ Node
	if (first == NULL)
	{
		return false;
	}

	// �M�� Node
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

	// �Y�䤣��
	if (current == NULL)
	{
		return false;
	}
		
	if (current->l_child == NULL && current->r_child == NULL)
	{
		// �p�G�� Node ���U�S Child
		// �N�����屼
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
		// �p�G�� Node ���U����� Child
		//   �� r_child �� root ���l�𤤳̤p�� Node ���ɦ��Q�R���� Node
		//   �A��r_child �� root ���l�𤤳̤p�� Node �屼
		//     �]���O�̤p�� Node, �� Node �u�|�����L r_child ����� case

		Node<int, string>* r_parent; // r_child �� root ���l�𤤳̤p�� Node �� parent
		Node<int, string>* r_lookahead; // ���e���U�@�� Node �M��O�_���̤p�� Node

		r_parent = current->r_child;
		r_lookahead = current->r_child;

		while (r_lookahead->l_child != NULL)
		{
			r_parent = r_lookahead;
			r_lookahead = r_parent->l_child;
		}

		// �� r_child �� root ���l�𤤳̤p�� Node ���ɦ��Q�R���� Node
		
	}
	else
	{
		// �p�G�� Node ���U���@�� Child
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
	// �p�G�ڥ��S������ Node
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
	
	// �Y�䤣��
	return NULL;
}

void BST::printTree()
{
}
