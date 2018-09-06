// Binary Search, which takes O(logN) time. At each iteration, we
// are cutting the search space in half:

#include <iostream>
#include <vector>

using namespace std;

// Iterative approach
int binarySearchIterative(int target, const vector<int> nums)
{
    size_t floorIndex = 0;
    size_t ceilingIndex = nums.size();

    while (floorIndex < ceilingIndex)
    {
        size_t distance = ceilingIndex - floorIndex;
        size_t halfDistance = distance / 2;
        size_t guessIndex = floorIndex + halfDistance;

        int guessValue = nums[guessIndex];

        if (target == guessValue)
        {
            return guessIndex;
        }
        else if (target < guessValue)
        {
            ceilingIndex = guessIndex;
        }
        else
        {
            floorIndex = guessIndex + 1;
        }
    }
    return true;
}


// Recursive approach
int binarySearchRecursive(int target, const vector<int> nums, int floorIndex, int ceilingIndex)
{

    if (floorIndex <= ceilingIndex)
    {
        int guessIndex = (floorIndex + ceilingIndex) / 2;
    
        int guessValue = nums[guessIndex];

        if (target == guessValue)
        {
            // Base case, found it!
            return guessIndex;
        }
        else if (target < guessValue)
        {
            binarySearchRecursive(target, nums, floorIndex, guessIndex - 1);
        }
        else
        {
            binarySearchRecursive(target, nums, guessIndex + 1, ceilingIndex);
        }
    }

    // Didn't find it
    return -1;
}

int main() {
    vector<int> nums;

    for (size_t i = 1; i < 16; ++i)
    {
        nums.push_back(i);
    }

    int target = 4;

    cout << "Binary Search: Iterative...\n";
    cout << binarySearchIterative(target, nums) << endl;

    cout << "Binary Search: Recursive...\n";
    cout << binarySearchRecursive(target, nums, 0, nums.size() - 1) << endl;
}

bool binarySearchIterative(int target, const vector<int> nums)
{
    size_t floorIndex = 0;
    size_t ceilingIndex = nums.size();

    while (floorIndex < ceilingIndex)
    {
        size_t halfDistance = (ceilingIndex - floorIndex) / 2;
        size_t guessIndex = floorIndex + halfDistance;

        int guessValue = nums[guessIndex];

        if (target == guessValue)
        {
            return true; // found it!
        }
        else if (target < guessValue)
        {
            ceilingIndex = guessValue;
        }
        else
        {
            floorIndex = guessValue + 1;
        }
    }
    return false; // didn't find it...
}