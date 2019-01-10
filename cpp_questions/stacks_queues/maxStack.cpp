// Implement a maxStack class, which provides a getMax() function that retrieves the
// largest value in the stack. All functions, including getMax(), should work in
// O(n) time.

// SOLUTION: By using the stack data struct, we can implement a normal stack to
// hold all pushed items, and another stack, maxestack, to push a number that is
// greater than the current greatest (and top num) of the normal stack. This allows
// us to keep track of all the maxes, and if one gets pop() out, getting the next
// max is still O(1) time.


#include <iostream>
#include <stack>

using namespace std;

// fill in the definitions for push(), pop(), and getMax()


class MaxStack
{
public:
    void push(int item)
    {
        stack_.push(item);
        if (maxesStack_.empty() || item >= maxesStack_.top())
        {
            maxesStack_.push(item);
        }
        
    }

    int pop()
    {
        int item = stack_.top();
        stack_.pop();
        if (item == maxesStack_.top())
        {
            maxesStack_.pop();
        }
        return item;
    }

    int getMax() const
    {
        return maxesStack_.top();
    }

private:
    stack<int> stack_;
    stack<int> maxesStack_;
    
};

