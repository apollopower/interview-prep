// Implement a queue using two stacks:

#include <iostream>
#include <stack>

using namespace std;

class QueueWithStacks
{
    public:

        void enqueue(int item)
        {
            inStack_.push(item);
        }

        int dequeue()
        {
            if (outStack_.empty())
            {
                while (!inStack_.empty())
                {
                    outStack_.push(inStack_.top());
                    inStack_.pop();
                }

                if (outStack_.empty())
                {
                    throw runtime_error("Can't dequeue from an empty queue\n");
                }
            }

            int item = outStack_.top();
            outStack_.pop();
            return item;
        }

    private:

        stack<int> inStack_;
        stack<int> outStack_;
}