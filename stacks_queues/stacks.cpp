#include <iostream>

using namespace std;

const int SIZE = 5;

class STACK
{
    private:

        int num[SIZE];
        int top;

    public:

        STACK(); // Constructor
        int pop();
        int push(int n);
        bool isEmpty();
        bool isFull();
        void displayItems();

};

STACK::STACK()
{
    top = -1;
}

bool STACK::isEmpty()
{
    if (top == -1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool STACK::isFull()
{
    if (top == SIZE - 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int STACK::push(int n)
{
    if (isFull())
    {
        cout << "Stack is already full\n";
        return 0;
    }
    ++top;
    num[top] = n;
    return n;
}

int STACK::pop()
{
    if (isEmpty())
    {
        cout << "Stack is already empty\n";
        return 0;
    }

    // to store & print the num that is deleted
    int tmp = num[top];

    --top;
    return tmp;
}

void STACK::displayItems()
{
    for (size_t i = 0; i < SIZE; ++i)
    {
        cout << num[i] << endl;
    }
}

int main() {
    STACK myStack;

    for (int i = 0; i < 10; ++i)
    {
        myStack.push(i);
    }

    myStack.displayItems();
}