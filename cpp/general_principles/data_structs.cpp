// Notes on Data Structures and General CS Principles

// 1. Random Access Memory (RAM)

// RAM is our working memory, which stores our data when running
// code.

// ....


// 2. Linked Lists

// LinkedList Lookup example:

LinkedListNode* getItemInLinkedList(LinkedListNode *head, size_t i)
{
    LinkedListNode *currentNode = head;
    size_t currentPosition = 0;

    while (currentPosition != nullptr) {

        if (currentPosition == i) {
            // Found it!
            return currentNode;
        }

        // Move to the next node...
        currentNode = currentNode->next;
        ++currentPosition;
    }
}

// 3. Hash Tables

