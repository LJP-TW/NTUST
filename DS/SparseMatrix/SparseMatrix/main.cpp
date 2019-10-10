#include <iostream>
#include <sstream>
#include <string>

using namespace std;

struct triple {
    int row;
    int column;
    int value;
};

class Matrix;

struct MatrixNode {
    MatrixNode() :right(this), down(this), isHead(false) {};
    MatrixNode(bool, triple*);
    MatrixNode *right;
    MatrixNode *down;

    bool isHead;
    union {
        MatrixNode *next;
        triple data;
    };
};

MatrixNode::MatrixNode(bool isHead, triple* data)
{
    this->isHead = isHead;
    if (isHead)
        next = right = down = this;
    else
        this->data = *data;
}

class Matrix {
public:
    Matrix() :headnode(NULL) {};

    // Initialize the sparse matrix *this to the sparse matrix a.
    Matrix(const Matrix& a);

    ~Matrix();

    // Read in the matrix and set it up according to the representation of this section.
    // The first input line gives the matrix dimensions and number of nodes in the matrix. 
    // The next several lines contain one triple, (row, column, value), each. 
    // The last triple ends the input file. These triples are in increasing order by rows. 
    // Within rows, the triples are in increasing order of columns. 
    // The data is to be read in one line at a time and converted to internal representation.
    friend istream& operator >>(istream& is, Matrix& m);

    // Output the terms of m. 
    // Output format¡G (row, column, value). 
    // The output is ordered by rows and within rows by columns.
    friend ostream& operator <<(ostream& os, const Matrix& m);

    const Matrix& operator = (const Matrix& a);
    Matrix operator + (const Matrix& b) const;
    Matrix operator - (const Matrix& b) const;
    Matrix operator * (const Matrix& b) const;

    Matrix Transpose() const;
private:
    MatrixNode *headnode;
};

Matrix::Matrix(const Matrix& a)
{
    stringstream ss;
    ss << a.headnode->data.row << " " << a.headnode->data.column << " " << a.headnode->data.value << endl;
    ss << a;
    ss >> *this;
}

Matrix::~Matrix()
{
    MatrixNode *entry = headnode;
    MatrixNode *temp;

    // Loop through every column head
    entry = entry->right;
    while (entry != headnode)
    {
        // Loop through item in column
        entry = entry->down;
        while (entry->isHead != true)
        {
            temp = entry;
            entry = entry->down;
            free(temp);
        }

        temp = entry;
        entry = entry->next;
        free(temp);
    }
    
    free(headnode);
}

istream& operator >>(istream & is, Matrix & m)
{
    triple n;
    int size;
    int currentR;
    MatrixNode *last;
    MatrixNode **head;

    is >> n.row >> n.column >> n.value;
    size = n.row >= n.column ? n.row : n.column;

    // headnode records dimension info
    m.headnode = new MatrixNode(false, &n);

    if (size == 0)
        return is;

    head = new MatrixNode *[size];
    
    // Initialize head
    for (int i = 0; i < size; ++i)
    {
        head[i] = new MatrixNode(true, NULL);
    }

    last = head[0];

    // Receive input
    currentR = 0;
    while (n.value)
    {
        triple temp;
        
        is >> temp.row >> temp.column >> temp.value;

        // Close current row
        if (currentR < temp.row)
        {
            last->right = head[currentR];
            currentR = temp.row;
            last = head[currentR];
        }

        // Append new node at currentR
        last = last->right = new MatrixNode(false, &temp);

        // Append this node at m.column, using MatrixNode.next to record last element of column
        head[temp.column]->next = head[temp.column]->next->down = last;
        --n.value;
    }

    // Close row
    last->right = head[currentR];

    // Close columns
    for (int i = 0; i < size; ++i)
    {
        head[i]->next->down = head[i];
    }

    // Link all heads
    for (int i = 0; i < size - 1; ++i)
    {
        head[i]->next = head[i + 1];
    }
    head[size - 1]->next = m.headnode;
    m.headnode->down = m.headnode->right = head[0];
    delete[] head;

    return is;
}

ostream& operator <<(ostream & os, const Matrix & m)
{
    MatrixNode *entry = m.headnode;

    if (entry->data.row == 0 && entry->data.column == 0)
        return os;
    
    entry = entry->right;
    do
    {
        entry = entry->right;
        while (entry->isHead != true)
        {
            os << entry->data.row << " " << entry->data.column << " " << entry->data.value << endl;
            entry = entry->right;
        }
        entry = entry->next;
    } while (entry != m.headnode);

    return os;
}

const Matrix& Matrix::operator = (const Matrix& a)
{
    stringstream ss;
    ss << a.headnode->data.row << " " << a.headnode->data.column << " " << a.headnode->data.value << endl;
    ss << a;
    ss >> *this;
    return *this;
}

Matrix Matrix::operator + (const Matrix& b) const
{
    Matrix a = *this;

    MatrixNode *ap = a.headnode;
    MatrixNode *bp = b.headnode;
    MatrixNode *entry, *prev;
    MatrixNode **head;
    int size;

    if (ap->data.row != bp->data.row || ap->data.column != bp->data.column)
        throw "Error dimensions!";

    size = ap->data.row >= ap->data.column ? ap->data.row : ap->data.column;
    head = new MatrixNode*[size];

    // Initialize head
    head[0] = a.headnode->right;
    for (int i = 1; i < size; ++i)
    {
        head[i] = head[i - 1]->next;
    }

    // For every item in sparse matrix b
    bp = bp->right;
    while (bp != b.headnode)
    {
        bp = bp->right;
        while (bp->isHead != true)
        {
            // ---- Create new data matrixnode
            MatrixNode *np = new MatrixNode(false, &(bp->data));

            // ---- Add to row list
            prev = head[bp->data.row];
            entry = prev->right;
            
            while (entry->isHead != true && np->data.column > entry->data.column)
            {
                prev = entry;
                entry = entry->right;
            }

            if (entry->isHead != true && np->data.column == entry->data.column)
            {
                // Overlap
                entry->data.value += np->data.value;

                if (entry->data.value == 0)
                {
                    // Detach node from row list
                    prev->right = entry->right;
                    // Detach node from column list and free np and free this node later.
                }
            }
            else
            {
                // Case for:
                // - First item
                // - Last item
                // - item that has different column number
                prev->right = np;
                np->right = entry;
                
                // Add node count
                ++a.headnode->data.value;
            }
            
            // ---- Add to column list
            prev = head[bp->data.column];
            entry = prev->down;

            while (entry->isHead != true && np->data.row > entry->data.row)
            {
                prev = entry;
                entry = entry->down;
            }
            
            if (entry->isHead != true && np->data.row == entry->data.row)
            {
                // OVERLAP
                if (entry->data.value == 0)
                {
                    // Detach from column list
                    prev->down = entry->down;
                    // Delete this node
                    delete entry;
                    // Subtract node count
                    --a.headnode->data.value;
                }

                // No need to add new item.
                delete np;
            }
            else
            {
                // Case for:
                // - First item
                // - Last item
                // - item that has different row number
                prev->down = np;
                np->down = entry;
            }

            bp = bp->right;
        }
        bp = bp->next;
    }
    
    delete[] head;
    return a;
}

Matrix Matrix::operator - (const Matrix& b) const
{
    Matrix a = *this;

    MatrixNode *ap = a.headnode;
    MatrixNode *bp = b.headnode;
    MatrixNode *entry, *prev;
    MatrixNode **head;
    int size;

    if (ap->data.row != bp->data.row || ap->data.column != bp->data.column)
        throw "Error dimensions!";

    size = ap->data.row >= ap->data.column ? ap->data.row : ap->data.column;
    head = new MatrixNode*[size];

    // Initialize head
    head[0] = a.headnode->right;
    for (int i = 1; i < size; ++i)
    {
        head[i] = head[i - 1]->next;
    }

    // For every item in sparse matrix b
    bp = bp->right;
    while (bp != b.headnode)
    {
        bp = bp->right;
        while (bp->isHead != true)
        {
            // ---- Create new data matrixnode
            MatrixNode *np = new MatrixNode(false, &(bp->data));
            np->data.value = -np->data.value;

            // ---- Add to row list
            prev = head[bp->data.row];
            entry = prev->right;

            while (entry->isHead != true && np->data.column > entry->data.column)
            {
                prev = entry;
                entry = entry->right;
            }

            if (entry->isHead != true && np->data.column == entry->data.column)
            {
                // Overlap
                entry->data.value += np->data.value;

                if (entry->data.value == 0)
                {
                    // Detach node from row list
                    prev->right = entry->right;
                    // Detach node from column list and free np and free this node later.
                }
            }
            else
            {
                // Case for:
                // - First item
                // - Last item
                // - item that has different column number
                prev->right = np;
                np->right = entry;

                // Add node count
                ++a.headnode->data.value;
            }

            // ---- Add to column list
            prev = head[bp->data.column];
            entry = prev->down;

            while (entry->isHead != true && np->data.row > entry->data.row)
            {
                prev = entry;
                entry = entry->down;
            }

            if (entry->isHead != true && np->data.row == entry->data.row)
            {
                // OVERLAP
                if (entry->data.value == 0)
                {
                    // Detach from column list
                    prev->down = entry->down;
                    // Delete this node
                    delete entry;
                    // Subtract node count
                    --a.headnode->data.value;
                }

                // No need to add new item.
                delete np;
            }
            else
            {
                // Case for:
                // - First item
                // - Last item
                // - item that has different row number
                prev->down = np;
                np->down = entry;
            }

            bp = bp->right;
        }
        bp = bp->next;
    }

    delete[] head;
    return a;
}

Matrix Matrix::operator * (const Matrix& b) const
{
    // m = (*this) * b
    Matrix m;
    triple headTriple;
    int currentR, currentC;
    int size;
    MatrixNode *last, *entryA, *entryB, *rowHead, *columnHead;
    MatrixNode **head;

    // ---- Error detection
    if(this->headnode->data.column != b.headnode->data.row)
        throw "Error dimensions!";

    // ---- Initialize m
    // headnode records dimension info
    headTriple.row = this->headnode->data.row;
    headTriple.column = b.headnode->data.column;
    headTriple.value = 0;

    m.headnode = new MatrixNode(false, &headTriple);

    size = this->headnode->data.row >= b.headnode->data.column ? this->headnode->data.row : b.headnode->data.column;

    head = new MatrixNode *[size];

    for (int i = 0; i < size; ++i)
    {
        head[i] = new MatrixNode(true, NULL);
    }

    // ---- Multiplication
    currentR = 0;

    // Loop each row of (*this)
    entryA = this->headnode->right;
    while (entryA != this->headnode)
    {
        last = head[currentR];
        currentC = 0;

        // Loop each column of b
        entryB = b.headnode->right;
        while (entryB != b.headnode)
        {
            // Initialize triple
            triple temp;
            temp.row = currentR;
            temp.column = currentC;
            temp.value = 0;

            // Loop each item in row of (*this), and find the multiplier in column of b
            rowHead = entryA;
            entryA = entryA->right;
            while (entryA->isHead != true)
            {
                columnHead = entryB;
                entryB = entryB->down;

                if (columnHead == entryB)
                {
                    // this column of b has no item, no need to go on
                    entryA = rowHead;
                    break;
                }

                while (entryB->isHead != true)
                {
                    if (entryA->data.column == entryB->data.row)
                    {
                        temp.value += (entryA->data.value * entryB->data.value);
                    }

                    if (entryA->data.column <= entryB->data.row)
                    {
                        // Never/Already find multiplier, no need to go on
                        entryB = columnHead;
                        break;
                    }
                    
                    // next item in column of b
                    entryB = entryB->down;
                }

                // next item in row of (*this)
                entryA = entryA->right;
            }

            // Add new node
            if (temp.value != 0)
            {
                last = last->right = new MatrixNode(false, &temp);
                head[temp.column]->next = head[temp.column]->next->down = last;
                ++m.headnode->data.value;
            }

            // next column of b
            entryB = entryB->next;
            ++currentC;
        }

        // Close row
        last->right = head[currentR];

        // next row of (*this)
        entryA = entryA->next;
        ++currentR;
    }

    // Close column
    for (int i = 0; i < size; ++i)
    {
        head[i]->next->down = head[i];
    }

    // Link all heads
    for (int i = 0; i < size - 1; ++i)
    {
        head[i]->next = head[i + 1];
    }
    head[size - 1]->next = m.headnode;
    m.headnode->down = m.headnode->right = head[0];

    delete[] head;
    return m;
}

Matrix Matrix::Transpose() const
{
    Matrix m;

    triple temp;
    int size;
    int currentR;
    MatrixNode *last, *entry;
    MatrixNode **head;

    temp.column = this->headnode->data.row;
    temp.row = this->headnode->data.column;
    temp.value = this->headnode->data.value;

    size = temp.row >= temp.column ? temp.row : temp.column;

    // headnode records dimension info
    m.headnode = new MatrixNode(false, &temp);

    if (size == 0)
        return m;

    head = new MatrixNode *[size];

    // Initialize head
    for (int i = 0; i < size; ++i)
    {
        head[i] = new MatrixNode(true, NULL);
    }

    // For loop each column
    currentR = 0;
    entry = this->headnode->right;
    while (entry != this->headnode)
    {
        last = head[currentR];
        entry = entry->down;
        while (entry->isHead != true)
        {
            temp.column = entry->data.row;
            temp.row = entry->data.column;
            temp.value = entry->data.value;

            // Append new node at currentR
            last = last->right = new MatrixNode(false, &temp);

            // Append this node at m.column, using MatrixNode.next to record last element of column
            head[temp.column]->next = head[temp.column]->next->down = last;

            entry = entry->down;
        }

        // close current row
        last->right = head[currentR];

        entry = entry->next;
        ++currentR;
    }

    // Close columns
    for (int i = 0; i < size; ++i)
    {
        head[i]->next->down = head[i];
    }

    // Link all heads
    for (int i = 0; i < size - 1; ++i)
    {
        head[i]->next = head[i + 1];
    }
    head[size - 1]->next = m.headnode;
    m.headnode->down = m.headnode->right = head[0];
    delete[] head;
    
    return m;
}

int main()
{
    string cmd;
    while (cin >> cmd)
    {
        if (cmd == "+")
        {
            Matrix a, b;
            cin >> a >> b;
            try
            {
                cout << a + b;
            }
            catch (const char *msg)
            {
                cout << msg << endl;
            }
        }
        else if (cmd == "T")
        {
            Matrix a;
            cin >> a;
            cout << a.Transpose();
        }
        else if (cmd == "-")
        {
            Matrix a, b;
            cin >> a >> b;
            try
            {
                cout << a - b;
            }
            catch (const char *msg)
            {
                cout << msg << endl;
            }
        }
        else if (cmd == "*")
        {
            Matrix a, b;
            cin >> a >> b;
            try
            {
                cout << a * b;
            }
            catch (const char *msg)
            {
                cout << msg << endl;
            }
        }
    }
    return 0;
}