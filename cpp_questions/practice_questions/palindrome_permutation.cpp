#include <iostream>
#include <string>
#include <unordered_set>

bool hasPalindromePermutation(const string& str)
{
    unordered_set<char> noPairs;

    for (size_t i = 0; i < str.length(); i++)
    {
        char currentChar = str[i];

        if (noPairs.find(currentChar) == noPairs.end())
        {
            noPairs.insert(currentChar);
        }
        else
        {
            noPairs.erase(currentChar);
        }
    }

    return noPairs.size() <= 1;
}