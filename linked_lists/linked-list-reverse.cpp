#include <iostream>
#include <vector>

using namespace std;

class LinkedListNode {
public:
    int intValue_;
    LinkedListNode* next_;

    LinkedListNode(int value) :
        intValue_(value),
        next_(nullptr)
    {
    }
};

LinkedListNode* reverse(LinkedListNode* headOfList)
{
    // reverse the linked list in place
    LinkedListNode* currentNode = headOfList;
    LinkedListNode* previousNode = nullptr;
    LinkedListNode* nextNode = nullptr;
    
    while (currentNode)
    {
        nextNode = currentNode->next_;
        
        currentNode->next_ = previousNode;
        
        previousNode = currentNode;
        
        currentNode = nextNode;
    }
    
    return previousNode;
}