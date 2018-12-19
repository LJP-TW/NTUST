#include "bst.h"

Bst::Bst()
{
	this->root = NULL;
}

void Bst::ins(int data)
{
	// 先確認 data 不在 tree 裡面
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
			++current->leftSize;

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
	// 先確認 data 在 tree 裡面
	if (!this->sea(data))
	{
		throw BstDeleteException();
	}

	Node *current = this->root;
	// current 是否為 previous 的 left
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
					current->left->parent = current->parent;
				}
				else
				{
					this->root = current->left;
					this->root->parent = NULL;
				}

				delete current;
			}
			else if (current->left == NULL && current->right != NULL)
			{
				if (current->parent != NULL)
				{
					if (isLeft)
					{
						current->parent->left = current->right;
					}
					else
					{
						current->parent->right = current->right;
					}
					current->right->parent = current->parent;
				}
				else
				{
					this->root = current->right;
					this->root->parent = NULL;
				}

				delete current;
			}
			else
			{
				// 尋找左子樹最大的值
				Node *sub_current = current->left;
				bool sub_isLeft = true;

				while (sub_current->right != NULL)
				{
					sub_current = sub_current->right;
					sub_isLeft = false;
				}

				// 取代要被刪除的點的data
				current->data = sub_current->data;
				--current->leftSize;

				// 刪除替身
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
						sub_current->left->parent = sub_current->parent;
					}
					else
					{
						sub_current->parent->right = sub_current->left;
						sub_current->right->parent = sub_current->parent;
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
			--current->leftSize;

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
		if (r == current->leftSize)
		{
			return current->data;
		}
		else if (r > current->leftSize)
		{
			r -= current->leftSize;
			current = current->right;
		}
		else if (r < current->leftSize)
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

int Bst::avg(int l, int u)
{
	try
	{
		int total = 0;
		for (int i = l; i <= u; ++i)
		{
			total += this->rank(i);
		}

		return (total / (u - l + 1));
	}
	catch (BstRankException& e)
	{
		throw BstAvgException();
	}
}
