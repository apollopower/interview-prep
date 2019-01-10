#include <iostream>
#include <vector>

using namespace std;

vector<int> countingSort(const vector<int>& theVector, int maxValue)
{
    // Array of 0's at indices 0...maxValue
    vector<size_t> numCounts(maxValue + 1);

    // Populate numCounts
    for (int num: theVector)
    {
        // At each index which corresponds with the num, we keep
        // track of the count
        ++numCounts[num];
    }

    // Populate the final sorted vector
    vector<int> sortedVector(theVector.size());
    size_t currentSortedIndex = 0;

    // For each num in numCounts
    for (size_t num = 0; num < numCounts.size(); ++num)
    {
        size_t count = numCounts[num];

        // For the number of times the number occurs:
        for (size_t i = 0; i < count; ++i)
        {
            // Add it to the sorted array, and go the next
            // idx of our sorted array
            sortedVector[currentSortedIndex] = num;
            ++currentSortedIndex;
        }
    }

    return sortedVector;
}