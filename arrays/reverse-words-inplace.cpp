#include <iostream>
#include <string>

using namespace std;

void reverseCharacters(string& message, size_t leftIndex, size_t rightIndex)
{
    // Checking if string is empty
    if (message.empty())
    {
        return;
    }
    
    while (leftIndex < rightIndex)
    {
        swap(message[leftIndex], message[rightIndex]);
        ++leftIndex;
        --rightIndex;
    }
    return;
}

void reverseWords(string& message)
{
    // checking if string empty
    if (message.empty())
    {
        return;
    }
    
    // 1. Reverse ALL Characters
    
    reverseCharacters(message, 0, message.length() -1);
    
    // 2. un-reverse each word.
    
    // 2a. Find beginning and end of each word:
    size_t currentWordStart = 0;
    for (size_t i = 0; i <= message.length(); ++i)
    {
        if (i == message.length() || message[i] == ' ')
        {
            reverseCharacters(message, currentWordStart, i - 1);
            currentWordStart = i + 1;
        }
    }
    
}