#include <iostream>
#include <stack>

using namespace std;

class maxStack
{
    private:
        stack<int> stack_;
        stack<int> maxStack_;

    public:

        void push(int item)
        {
            stack_.push(item);
            if (maxStack.empty() || item >= maxStack_.top())
            {
                maxStack_.push(item);
            }
        }

        int pop()
        {
            int item = stack_.top();
            stack_.pop();
            if (item == maxStack_.top())
            {
                maxStack_.pop();
            }
            return item;
        }

        // Last item in maxStack is the max item in our stack
        int getMax()
        {
            return maxStack_.top();
        }
};
