#include "bst.h"

Bst::Bst()
{
	this->root = NULL;
}

void Bst::ins(int data)
{
	// ���T�{ data ���b tree �̭�
	if (this->sea(data))
	{
		throw BstInsertException();
	}

	if (this->root == NULL)
	{
		this->root = new Node(NULL, NULL, NULL, data, 1);
		return;
	}

	Node *current = this->root;

	while (true) {
		if (data > current->data)
		{
			if (current->right == NULL)
			{
				current->right = new Node(current, NULL, NULL, data, 1);
				return;
			}
			current = current->right;
		}
		else
		{
			++current->rank;

			if (current->left == NULL)
			{
				current->left = new Node(current, NULL, NULL, data, 1);
				return;
			}
			current = current->left;
		}
	}
	
	return;
}

void Bst::del(int data)
{
	// ���T�{ data �b tree �̭�
	if (!this->sea(data))
	{
		throw BstDeleteException();
	}

	Node *current = this->root;
	// current �O�_�� previous �� left
	bool isLeft = false;

	while (true) 
	{
		if (data == current->data)
		{
			if (current->left == NULL && current->right == NULL)
			{
				if (current->parent != NULL)
				{
					if (isLeft) 
					{
						current->parent->left = NULL;
					}
					else
					{
						current->parent->right = NULL;
					}
				}
				else
				{
					this->root = NULL;
				}

				delete current;				
			}
			else if (current->left != NULL && current->right == NULL)
			{
				if (current->parent != NULL)
				{
					if (isLeft)
					{
						current->parent->left = current->left;
					}
					else
					{
						current->parent->right = current->left;
					}
				}
				else
				{
					this->root = current->left;
				}

				delete current;
			}
			else if (current->left == NULL && current->right != NULL)
			{
				if (current->parent!= NULL)
				{
					if (isLeft)
					{
						current->parent->left = current->right;
					}
					else
					{
						current->parent->right = current->right;
					}
				}
				else
				{
					this->root = current->right;
				}

				delete current;
			}
			else
			{
				// �M�䥪�l��̤j����
				Node *sub_current = current->left;
				bool sub_isLeft = true;

				while (sub_current->right != NULL)
				{
					sub_current = sub_current->right;
					sub_isLeft = false;
				}

				// ���N�n�Q�R�����I��data
				current->data = sub_current->data;
				--current->rank;

				// �R������
				if (sub_current->left == NULL)
				{
					if (sub_isLeft)
					{
						sub_current->parent->left = NULL;
					}
					else
					{
						sub_current->parent->right = NULL;
					}
				}
				else
				{
					if (sub_isLeft)
					{
						sub_current->parent->left = sub_current->left;
					}
					else
					{
						sub_current->parent->right = sub_current->left;
					}
				}
				delete sub_current;
			}

			return;
		}
		else if (data > current->data)
		{
			current = current->right;
			isLeft = false;
		}
		else if (data < current->data)
		{
			--current->rank;

			current = current->left;
			isLeft = true;
		}
	}

	return;
}

bool Bst::sea(int data)
{
	Node *current = this->root;

	while (current != NULL)
	{
		if (data == current->data)
		{
			return true;
		}
		else if (data > current->data)
		{
			current = current->right;
		}
		else if (data < current->data)
		{
			current = current->left;
		}
	}

	return false;
}

int Bst::rank(int r)
{
	if (this->root == NULL)
	{
		throw BstRankException();
	}

	Node *current = this->root;

	while (current != NULL)
	{
		if (r == current->rank)
		{
			return current->data;
		}
		else if (r > current->rank)
		{
			r -= current->rank;
			current = current->right;
		}
		else if (r < current->rank)
		{
			current = current->left;
		}
	}

	throw BstRankException();
}

int Bst::minelement(int threshold)
{
	try
	{
		int n = this->rank(1);
		int r = 1;

		while ((threshold -= n) > 0)
		{
			++r;
			n = this->rank(r);
		}

		return n;
	}
	catch (BstRankException& e)
	{
		throw BstMinelementException();
	}
}
