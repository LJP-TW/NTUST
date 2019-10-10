#include <iostream>
#include <string>

using namespace std;

// Implementation of stack
template<class T>
class myStackItem {
public:
    myStackItem();
    myStackItem(T value);

    T value;
    myStackItem *prev;
};

template<class T>
class myStack {
public:
    myStack();

    // Accessing functions
    T top();

    // Capacity
    bool empty();

    // Modifiers
    void push(T value);
    void pop();

private:
    // Stack item, linked list
    myStackItem<T> *head;
};

template<class T>
myStackItem<T>::myStackItem() : value(0), prev(NULL)
{}

template<class T>
myStackItem<T>::myStackItem(T value) : value(value), prev(NULL)
{}

template<class T>
myStack<T>::myStack() : head(NULL)
{}

template<class T>
T myStack<T>::top()
{
    if (head != NULL)
    {
        return head->value;
    }
    return NULL;
}

template<class T>
bool myStack<T>::empty()
{
    return head != NULL ? false : true;
}

template<class T>
void myStack<T>::push(T value)
{
    myStackItem<T> *newNode = new myStackItem<T>(value);
    newNode->value = value;
    newNode->prev = head;
    head = newNode;
}

template<class T>
void myStack<T>::pop()
{
    if (empty())
    {
        return;
    }
    myStackItem<T> *oldNode = head;
    head = head->prev;
    delete oldNode;
}

string infix2postfix(string);
string infix2prefix(string);
string _infix2postfix(string, bool);

int main()
{
    string input;

    while (cin >> input)
    {
        cout << "Postfix: " << infix2postfix(input) << endl;
        cout << "Prefix: " << infix2prefix(input) << endl;
        cout << endl;
    }

    return 0;
}

int getOpPriority(char c, bool instack)
{
    if (c == '(' && instack)
    {
        // Lowest Priority
        return 0;
    }
    else if (c == '+' || c == '-')
    {
        return 1;
    }
    else if (c == '*' || c == '/')
    {
        return 2;
    }
    else if (c == '(' && !instack)
    {
        // Highest Priority
        return 100;
    }
}

string infix2postfix(string input)
{
    return _infix2postfix(input, true);
}

string infix2prefix(string input)
{
    string reverseInput = "";
    for (auto it = input.rbegin(); it != input.rend(); ++it)
    {
        if (*it == '(')
            reverseInput += ')';
        else if (*it == ')')
            reverseInput += '(';
        else
            reverseInput += *it;
    }

    reverseInput = _infix2postfix(reverseInput, false);

    input = "";
    for (auto it = reverseInput.rbegin(); it != reverseInput.rend(); ++it)
    {
        input += *it;
    }

    return input;
}

string _infix2postfix(string input, bool left2right)
{
    string result = "";
    myStack<char> opStack;

    for (auto it = input.begin(); it != input.end(); ++it)
    {
        char c = *it;

        if (c != '+' && c != '-' && c != '*' && c != '/' && c != '(' && c != ')')
        {
            result += c;
        }
        else
        {
            if (opStack.empty())
            {
                opStack.push(c);
            }
            else
            {
                if (c == ')')
                {
                    while (true)
                    {
                        char top = opStack.top();
                        opStack.pop();

                        if (top == '(')
                        {
                            break;
                        }

                        result += top;
                    }
                }
                else
                {
                    int coming = getOpPriority(c, false);

                    while (true)
                    {
                        char top = opStack.top();
                        int instack = getOpPriority(top, true);

                        if (!opStack.empty() && 
                            ((left2right && instack >= coming) ||
                            (!left2right && instack > coming))
                           )
                        {
                            result += top;
                            opStack.pop();
                            continue;
                        }
                        break;
                    }

                    opStack.push(c);
                }
            }
        }
    }

    while (!opStack.empty())
    {
        char c = opStack.top();
        opStack.pop();
        result += c;
    }

    return result;
}