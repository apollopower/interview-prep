#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;


// SOLUTION 1: Using a set
bool isUnique(string str)
{
  unordered_set<char> charSet;

  for (char c : str)
  {
    if (charSet.find(c) == charSet.end())
    {
      // Didn't find char in our set
      charSet.insert(c);
    }
    else
    {
      // We found it! Therefore not unique
      return false;
    }
  }

  return true;
}
// Complexity:

// Runtime -> Linear, O(n)
// **worst case technically O(n^2) because of the
// unordered_set, but HIGHLY unlikely to happen.
// This is would be due to a hash collision, which is solved
// By implementing a linkedList, which takes O(n) time to
// traverse**

// Space -> Linear, O(n)
// We are using a hashmap, which will grow linearly according to
// the input string

// Solution 2: Check every char with another
bool isUnique2(string str)
{
  for (size_t i = 0; i < str.length(); i++)
  {
    for (size_t j = 0; j < str.length(); j++)
    {
      if (str[i] == str[j] && i != j)
      {
        return false;
      }
    }
  }

  return true;
}
// Complexity:

// Runtime -> Quadratic, O(n^2)
// To optimize for space and not use addition data structures,
// we check every character against the others. This requires
// a nested for loop, and gives us a quadratic implementation,
// making the runtime much slower.

// Space -> Constant, O(1)
// We sacrificed speed for space. No additional data
// structures used. This is a great example of the 
// trade-offs one can make when designing an alogirthm.

int main()
{
  string testString = "jonas";

  cout << isUnique(testString) << endl;

  cout << isUnique2(testString) << endl;

}