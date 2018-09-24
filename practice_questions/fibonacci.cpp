// Write a function fib() that takes an integer 'n', and returns the
// nth Fibonacci number:

int fib(int n)
{
    // Edge case, check for negative input:
    if (n < 0) throw invalid_argument("No negative fibonacci number!");

    // Base cases, n is first 2 elements in the sequence 
    // (which are both 1)
    if (n == 1 || n == 2)
    {
        return 1;
    }

    // Iterative solution: set fibonacci var to return,
    // as well as the previous 2 numbers:
    int fib = 0;
    int prev1 = 1;
    int prev2 = 1;

    // Counter, to calculate fib up to desired n position:
    // (Starts at 2 because we already account for first 2 fibonacci nums)
    int counter = 2;
    while (counter < n)
    {
        fib = prev1 + prev2;
        prev2 = prev1;
        prev1 = fib;

        counter++;
    }

    return fib;
}

// Runtime: O(n) -> we iterate up to value of n
// Space: O(1) -> We keep track of fixed-size variables
//                to calculate fib