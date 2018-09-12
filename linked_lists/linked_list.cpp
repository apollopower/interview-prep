#include <iostream>

using namespace std;

struct Node {
    int value_;
    Node* next_;
};

Node* newNode(Node* head, int value)
{
    Node* newNode = new Node;
    newNode->value_ = value;
    newNode->next_ = nullptr;
    return newNode;
}

void deleteNode(Node* list, int value)
{
    Node* current = list;

    while (current != nullptr)
    {
        Node* next = current->next_;
        if (next->value_ == value)
        {
            current->next_ = next->next_;
            delete next;
        }
    }
}

int main()
{
    Node* list = nullptr;
    
    for (int i = 0; i < 10; i++)
    {
        list = newNode(list, i);
    }

    deleteNode(list, 6);

    // Node* currentNode = list;

    // while (currentNode)
    // {
    //     cout << currentNode->value_ << endl;
    //     currentNode = currentNode->next_;
    // }
    return 0;
}