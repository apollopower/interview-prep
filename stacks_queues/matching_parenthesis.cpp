// Write a function to return the position of a closing parenthesis,
// given a string and the position of the respected opening parenthesis

#include <iostream>
#include <string>

using namespace std;

size_t getClosingParen(const string& sentence, size_t openingParenIndex)
{
    // find the position of the matching closing parenthesis
    if (sentence[openingParenIndex] != '(')
    {
        throw runtime_error("not parenthesis");
    }
    
    int paren_count = 1;
    
    for (size_t i = openingParenIndex + 1; i < sentence.length(); i++)
    {
        if (sentence[i] == '(')
        {
            paren_count++;
        }
        else if (sentence[i] == ')')
        {
            paren_count--;
        }
        
        if (paren_count == 0)
        {
            return i;    
        }
    }
    
    throw runtime_error("Incorrect sentence structure");
    
}