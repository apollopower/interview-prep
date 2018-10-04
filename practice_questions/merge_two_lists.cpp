// Merge two given linked list:
// Input: 1 -> 2 -> 5 && 1 -> 3 -> 4
// Output: 1 -> 1 -> 2 -> 3 -> 4 -> 5

#include <vector>
#include <algorithm>

// Definition for linked list:
struct Node {
    int val;
    Node* next;
    Node(int x) : val(x), next(NULL) {}
};

// First basic solution: O(nlgn) time
Node* mergeTwoLists(Node* l1, Node* l2)
{
    if (l1 == NULL && l2 == NULL) return NULL;

    vector<int> values;

    Node* current = l1;
    while (current)
    {
        values.push_back(current->val);
        current = current->next;
    }

    current = l2;
    while (current)
    {
        values.push_back(current->val);
        current = current->next;
    }

    sort(values.begin(), values.end());

    Node* mergedList = new Node(values[0]);
    current = mergedList;
    for (int i = 0; i < values.size(); i++)
    {
        current->next = new Node(values[i]);
        current = current->next;
    }

    return mergedList;

}


// 2nd (and best) Solution: O(n) time

Node* mergeTwoLists(Node* l1, Node* l2)
{
    // Edge cases:
    if (!l1 && l2)
    {
        return l2;
    }
    else if (!l2 && l1)
    {
        return l1;
    }
    else if (!l1 && !l2)
    {
        return NULL;
    }

    if (l1->val < l2->val)
    {
        Node* mergedList = l1;
        l1 = l1->next;
    }
    else
    {
        Node* mergedList = l2;
        l2 = l2->next;
    }

    Node* current = mergedList;
    while (l1 && l2)
    {
        if (l1->val < l2->val)
        {
            current->next = l1
            
            l1 = l1->next;
        }
        else
        {
            current->next = l2;

            l2 = l2->next;
        }
        current = current->next;
    }

    if (l1) current->next = l1;
    if (l2) current->next = l2;

    return mergedList;

}