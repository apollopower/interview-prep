#include <iostream>
#include <sstream>
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

void deleteNode(LinkedListNode* nodeToDelete)
{
    // get the input node's next node, the one we want to skip to:
    LinkedListNode* nextNode = nodeToDelete->next_;
    
    if (nextNode)
    {
        // replace the input node's value and pointer with the next
        // node's value and pointer. The previous node now effectively
        // skips over the input node:
        nodeToDelete->intValue_ = nextNode->intValue_;
        nodeToDelete->next_ = nextNode->next_;
        delete nextNode;
    }
    else
    {
        // No next node, which means this is the last node. With the
        // current function, we cannot simply "delete" this node:
        throw invalid_argument("Can't delete the last node with this function\n");
    }

}
