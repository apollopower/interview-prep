#include <iostream>
#include <vector>

// C++11 lest unit testing framework
#include "lest.hpp"

using namespace std;

vector<int> mergeVectors(const vector<int>& myVector, const vector<int>& alicesVector)
{
    // Set up our mergedVector
    vector<int> mergedVectors(myVector.size() + alicesVector.size());
    
    size_t currentIndexAlices = 0;
    size_t currentIndexMine = 0;
    size_t currentIndexMerged = 0;
    
    while (currentIndexMerged < mergedVectors.size())
    {
        bool isMyVectorExhausted = currentIndexMine >= myVector.size();
        bool isAlicesVectorExhausted = currentIndexAlices >= alicesVector.size();
        
        // case: next comes from my vector
        // my vector must not be exhausted, and EITHER:
        // 1. Alice's vector IS exhausted, OR
        // 2. The current element in my vector is less than
        // the current element in Alice's vector
        if (!isMyVectorExhausted && (isAlicesVectorExhausted ||
            (myVector[currentIndexMine] < alicesVector[currentIndexAlices])))
        {
            mergedVectors[currentIndexMerged] = myVector[currentIndexMine];
            ++currentIndexMine;
        }
        // Case: next comes from Alice's vector
        else
        {
            mergedVectors[currentIndexMerged] = alicesVector[currentIndexAlices];
            ++currentIndexAlices;
        }
        
        ++currentIndexMerged;
    }
    return mergedVectors;
}