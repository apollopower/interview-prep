// Write a recurisce solution to the fibonacci problem.

// WARNING: Becareful with calculating repeat numbers within the sequence!
// for example, for the 5th fibonacci number, 4 & 3 (n - 1 & n - 2), both have all 
// numbers before that in common (1, 2). make sure you do not do any repeat calculations.



// SOLUTION

// Easiest way to solve this problem is to wrap up our function in a class, where
// we can keep track of previous calls, simply using a hashmap (unordered_map in c++)

// This is a method known as __Memoization__ in Dynamic Programming

#include <iostream>
#include <unordered_map>

using namespace std;

class Fib
{
    private:

        unordered_map<int, int> memo_;
    
    public:

        int fib(int n)
        {
            // First, check fo exceptions where n is a nonpositve number
            if (n < 0)
            {
                throw invalid_argument("Can't calculate negative fibonacci number!");
            }
            // Base case
            else if (n == 0 || n == 1)
            {
                return n;
            }
            // Checking to see if we have calculate 
            // fib for this number before!
            else if (memo_.find(n) != memo_.end())
            {
                cout << "Grabbing memo_[" << n << "]" << endl;
                return memo_[n];
            }
            // Finally, if we have not seen this number yet,
            // we have our recursive call, and save the result
            // to our hashmap:
            else
            {
                cout << "Computing fib[" << n << "]" << endl;
                int result = fib(n - 1) + fib(n - 2);

                // Hashing time:
                memo_[n] = result;

                // Retuning the fib for this number
                return result;
            }
        }
};


// The main function call is for demontration purposes
// only:
int main()
{
    int result = Fib().fib(10);

    cout << result << endl;

    return 0; 
}