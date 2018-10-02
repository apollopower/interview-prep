// Given a list of linkedlists, return one merged linked list,
// with all values sorted.

#include <vector>
#include <algorithm>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* mergeKLists(vector<ListNode*>& lists)
{
    vector<int> values;

    for (auto list : lists)
    {
        ListNode* currentNode = list;
        while (currentNode != NULL)
        {
            values.push_back(currentNode->val);
            currentNode = currentNode->next;
        }
        delete currentNode;
    }

    sort(values.begin(), values.end());

    ListNode* result = new ListNode(values[0])
    ListNode* currentNode = result;

    for (int i = 1; i < values.size(); ++i)
    {
        currentNode->next = new ListNode(values[i])
        currentNode = currentNode->next;
    }

    return result;
}

// Runtime: O(nlgn), superlinear, time.
// We need to go through all values in all linked lists, O(n) time
// We also need to sort all values O(nlgn) time.
// TOTAL = O(n + nlgn) => O(nlgn)

// Space Complexity: O(n), linear
// Creating space according to size of needed linkedlist.