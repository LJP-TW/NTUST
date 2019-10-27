#include <iostream>
#include <vector>

using namespace std;

struct node {
    int keyvalue;
    struct node *left;
    struct node *right;
    int leftsize;
    node(int keyvalue, struct node *left, struct node *right, int leftsize) :keyvalue(keyvalue), left(left), right(right), leftsize(leftsize) {};
};

class BST {
public:
    BST() :root(NULL) {};
    void insertNode(int keyvalue);
    void deleteNode(int keyvalue);
    void searchByValue(int keyvalue);
    void searchByRank(int rank);
    void showInorder();
    void showPreorder();
    void showPostorder();
private:
    void _showInorder(node *head);
    void _showPreorder(node *head);
    void _showPostorder(node *head);
    node *root;
};

void BST::insertNode(int keyvalue)
{
    node **head = &root;

    while (*head != NULL)
    {
        if (keyvalue > (*head)->keyvalue)
        {
            head = &((*head)->right);
        }
        else if (keyvalue < (*head)->keyvalue)
        {
            head = &((*head)->left);
        }
        else
        {
            throw "Duplicate data.";
        }
    }

    *head = new node(keyvalue, NULL, NULL, 1);

    // Update leftsize
    head = &root;

    while (*head != NULL)
    {
        if (keyvalue > (*head)->keyvalue)
        {
            head = &((*head)->right);
        }
        else if (keyvalue < (*head)->keyvalue)
        {
            ++(*head)->leftsize;
            head = &((*head)->left);
        }
        else
        {
            // Reach to the node that just be inserted.
            break;
        }
    }
}

void BST::deleteNode(int keyvalue)
{
    node **head = &root;
    bool found = false;

    while (*head != NULL)
    {
        if (keyvalue > (*head)->keyvalue)
        {
            head = &((*head)->right);
        }
        else if (keyvalue < (*head)->keyvalue)
        {
            head = &((*head)->left);
        }
        else
        {
            found = true;
            break;
        }
    }

    if (!found)
    {
        throw "No such value to delete.";
    }

    // Updating left size
    head = &root;

    while (*head != NULL)
    {
        if (keyvalue > (*head)->keyvalue)
        {
            head = &((*head)->right);
        }
        else if (keyvalue < (*head)->keyvalue)
        {
            --(*head)->leftsize;
            head = &((*head)->left);
        }
        else
        {
            break;
        }
    }

    // Delete the node
    if ((*head)->left == NULL && (*head)->right == NULL)
    {
        // This node is a leaf node, just delete it.
        delete(*head);
        *head = NULL;
    }
    else if ((*head)->right != NULL)
    {
        // This node has only right child or has both left child and right child, 
        // find the smallest node of right sub-tree to replace this node,
        // and delete the smallest node.
        node **smallest = &((*head)->right);
        while ((*smallest)->left != NULL)
        {
            // Updating left size
            // Right sub-tree needs to revise left size
            --(*smallest)->leftsize;

            smallest = &((*smallest)->left);
        }
        --(*smallest)->leftsize;

        // Take value of smallest node
        (*head)->keyvalue = (*smallest)->keyvalue;

        if ((*smallest)->right == NULL)
        {
            // If smallest node is leaf node, delete it.
            delete(*smallest);
            *smallest = NULL;
        }
        else
        {
            // If smallest node has right node, link this right child node, and delete it.
            node *tmp = *smallest;
            *smallest = (*smallest)->right;
            delete(tmp);
        }
    }
    else
    {
        // This node has only left child,
        // find the biggest node of left sub-tree to replace this node,
        // and delete the biggest node.
        node **biggest = &((*head)->left);

        // Updating left size, only this node needs to revise left size
        --(*head)->leftsize;

        while ((*biggest)->right != NULL)
        {
            biggest = &((*biggest)->right);
        }

        // Take value of smallest node
        (*head)->keyvalue = (*biggest)->keyvalue;

        if ((*biggest)->left == NULL)
        {
            // If biggest node is leaf node, delete it.
            delete(*biggest);
            *biggest = NULL;
        }
        else
        {
            // If biggest node has left node, link this left child node, and delete it.
            node *tmp = *biggest;
            *biggest = (*biggest)->left;
            delete(tmp);
        }
    }
}

void BST::searchByValue(int keyvalue)
{
    node **head = &root;
    bool found = false;
    int depth = 1, bufferIdx;
    vector<node *> buffer[2];
    
    while (*head != NULL)
    {
        if (keyvalue > (*head)->keyvalue)
        {
            ++depth;
            head = &((*head)->right);
        }
        else if (keyvalue < (*head)->keyvalue)
        {
            ++depth;
            head = &((*head)->left);
        }
        else
        {
            found = true;
            break;
        }
    }

    if (!found)
    {
        throw "No such value.";
    }

    cout << "LeftSize = " << (*head)->leftsize << ", Depth = " << depth << endl;
}

void BST::searchByRank(int rank)
{
    node **head = &root;
    bool found = false;
    int tmpRank = rank;
    
    while (*head != NULL)
    {
        if (tmpRank > (*head)->leftsize)
        {
            tmpRank -= (*head)->leftsize;
            head = &((*head)->right);
        }
        else if(tmpRank < (*head)->leftsize)
        {
            head = &((*head)->left);
        }
        else
        {
            found = true;
            break;
        }
    }

    if (!found)
    {
        throw "No such value.";
    }

    cout << "The " << rank << "th smallest is " << (*head)->keyvalue << endl;
}

void BST::_showInorder(node *head)
{
    if (head == NULL)
    {
        return;
    }

    _showInorder(head->left);
    cout << head->keyvalue << " ";
    _showInorder(head->right);
}

void BST::_showPreorder(node *head)
{
    if (head == NULL)
    {
        return;
    }

    cout << head->keyvalue << " ";
    _showPreorder(head->left);
    _showPreorder(head->right);
}

void BST::_showPostorder(node *head)
{
    if (head == NULL)
    {
        return;
    }

    _showPostorder(head->left);
    _showPostorder(head->right);
    cout << head->keyvalue << " ";
}

void BST::showInorder()
{
    _showInorder(root);
    cout << endl;
}

void BST::showPreorder()
{
    _showPreorder(root);
    cout << endl;
}

void BST::showPostorder()
{
    _showPostorder(root);
    cout << endl;
}

int main()
{
    BST tree;
    int cmd, value;
    while (cin >> cmd)
    {
        switch (cmd)
        {
        case 1:
            cin >> value;
            try
            {
                tree.insertNode(value);
                cout << "[INSERT SUCCESS]" << endl;
            }
            catch (const char *msg)
            {
                cout << msg << endl;
            }
            break;
        case 2:
            cin >> value;
            try
            {
                tree.deleteNode(value);
                cout << "[DELETE SUCCESS]" << endl;
            }
            catch (const char *msg)
            {
                cout << msg << endl;
            }
            break;
        case 3:
            cin >> value;
            try
            {
                tree.searchByValue(value);
            }
            catch (const char *msg)
            {
                cout << msg << endl;
            }
            break;
        case 4:
            cin >> value;
            try
            {
                tree.searchByRank(value);
            }
            catch (const char *msg)
            {
                cout << msg << endl;
            }
            break;
        case 5:
            tree.showInorder();
            break;
        case 6:
            tree.showPreorder();
            break;
        case 7:
            tree.showPostorder();
            break;
        default:
            break;
        }
    }
}