// Find the kth to last node, given a LinkedList, and a K value:

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

LinkedListNode* kthToLastNode(size_t k, LinkedListNode* head)
{
    // return the kth to last node in the linked list
    size_t listLength = 0;
    
    LinkedListNode* currentNode = head;
    
    while (currentNode != nullptr)
    {
        ++listLength;
        currentNode = currentNode->next_;
    }
    
    size_t placeToGo = (listLength - k) + 1;
    
    currentNode = head;
    size_t place = 0;
    
    while (currentNode != nullptr)
    {
        ++place;
        if (place == placeToGo)
        {
            return currentNode;
        }
        currentNode = currentNode->next_;
    }
    
    throw invalid_argument("K is a larger value than linked list\n");
    
    

    return head;
}