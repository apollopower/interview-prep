#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

bool checkPermutation(string str1, string str2)
{
  unordered_map<char, int> charMap;

  for (char c : str1)
  {
    charMap[c]++;
  }

  for (char c : str2)
  {
    charMap[c]--;
  }

  for (auto itr = charMap.begin(); itr != charMap.end(); itr++)
  {
    if (itr->second != 0)
    {
      return false;
    }
  }

  return true;
}
// Complexity:

// Time -> Linear, O(n)

// Space -> Linear, O(n)

int main()
{
  cout << checkPermutation("jonas", "sanojo") << endl;
}