#include <iostream>
#include <vector>
#include <set>

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


// O(n) Time and O(n) Space complexity Solution:
bool containsCycle(LinkedListNode* firstNode)
{
    // check if the linked list contains a cycle
    LinkedListNode* currentNode = firstNode;
    set<LinkedListNode*> nodeMap;
    
    while (currentNode != nullptr)
    {
        
        if (nodeMap.find(currentNode) != nodeMap.end())
        {
            // delete currentNode;
            return true;
        }
        else
        {
            nodeMap.insert(currentNode);
        }
        currentNode = currentNode->next_;
    }
    delete currentNode;
    

    return false;
}


// O(n) Time and O(1) Space Complexity Solution:
bool containsCycle(const LinkedListNode* firstNode)
{
    const LinkedListNode* slow = firstNode;
    const LinkedListNode* fast = firstNode;
    
    while (fast != nullptr && fast->next_)
    {
        slow = slow->next_;
        fast = fast->next_->next_;
        
        // Case: Fast laps Slow
        if (fast == slow)
        {
            return true;
        }
    }
    
    // We hit the end of the list:
    return false;
}