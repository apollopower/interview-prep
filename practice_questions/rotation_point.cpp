// Find the rotation point in sorted words list:

#include <iostream>
#include <string>
#include <vector>


// This answer uses a variation of binary search

size_t rotationPoint(vector<string> words)
{
    // First, set the floor and ceiling indexes:
    size_t floorIdx = 0;
    size_t ceilingIdx = words.size() - 1;

    while (floorIdx < ceilingIdx)
    {
        size_t guessIdx = floorIdx + ((ceilingIdx - floorIdx) / 2);

        // If guess word is (alphabetically) greater than the one in first position,
        // the "true" start cannot be on the left half of the list. Set the floor
        // to the guess value and now search the right half
        if (words[guessIdx] >= words[0])
        {
            floorIdx = guessIdx;
        }
        // If guess word is less than the first word, it means the rotation point lies
        // somewhere between the first word and the guess word (the left half). Set
        // ceiling to guess value and search the left half of list.
        else
        {
            ceilingIdx = guessIdx;
        }

        // Now check if floor and ceiling are next to each other. This means
        // ALWAYS the one on the right (ceilingIdx) will be the desired target,
        // since the list is sorted BUT NOT from the first idx.
        if (floorIdx + 1 == ceilingIdx)
        {
            break;
        }
    }
    // ceilingIdx holds the position of the "true" start of the list
    return ceilingIdx;
}