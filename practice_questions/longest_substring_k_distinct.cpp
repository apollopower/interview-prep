// Given a string, find the length of the longest substring
// that only includes K distinc characters:
// Input => "ebeac"
// Output => 3 (substring is "ebe")

#include <unordered_map>

using namespace std;

int longestSubtringKDistinct(string s, int k)
{
    unordered_map<char, int> charCount;
    int j = -1, maxLen = 0;

    for (int i = 0; i < s.size(); ++i)
    {
        ++charCount[s[i]];
        while (charCount.size() > k)
        {
            if (--charCount[s[++j]] == 0)
            {
                charCount.erase(s[j]);
            }
        }
        maxLen = max(maxLen, i - j)
    }
    return maxLen;
}

int main()
{
    return 0;
}