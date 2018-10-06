// For a bottom-up approach, we do not have to make recursive calls.

// The idea is that instead of making recursive calls until we hit a
// base case, we can "start from the beginning" of the problem instead
// of the reverse.

// For example, here is a recursive solution to multiplying all
// numbers from 1 to n:

int recurisveProduct1ToN(int n)
{
    if (n > 1)
    {
        return n * recurisveProduct1ToN(n - 1)
    }
    else
    {
        return 1;
    }
}

// This can be problematic if we use more memory than is on the call stack!
// We would get a stack overflow

// In the above example, we are working backwards from the base case. With
// a bottom up approach, we iterate and start at the beginning:

int bottomUpProduct1ToN(int n)
{
    int product = 1;
    for (int i = 1; i <= n; i++)
    {
        product *= i;
    }

    return product; 
}

// This solution uses O(n) time and O(1) space, where the recursive solution
// would take up O(n) time AND O(n) space.