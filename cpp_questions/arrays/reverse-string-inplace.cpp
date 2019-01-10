#include <iostream>
#include <string>

using namespace std;

void reverse(string& str)
{
    // reverse the input string in place
    int i = 0;
    int j = str.length() - 1;
    
    while (i < j)
    {
        char tmp = str[i];
        str[i] = str[j];
        str[j] = tmp;
        i++;
        j--;
    }
    return;
}

// Another solution, using size_t data type and swap()

void reverse_2(string& str)
{   
    // Edge case, string is empty:
    if (str.empty())
    {
        return;
    }

    // Size_t to keep track of indeces
    size_t leftIndex = 0;
    size_t rightIndex = str.length() - 1;

    while (leftIndex < rightIndex)
    {
        swap(str[leftIndex], str[rightIndex]);
    }

    // Move leftIndex forward; rightIndex back
    ++leftIndex;
    --rightIndex;
}