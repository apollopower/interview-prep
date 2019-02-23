#include <string>
#include <unordered_set>

class Solution {

    public:

    int numJewelsInStones(string J, string S) {
        unordered_set<char> jewels;
        int jewelCount = 0;

        for (char c : J) {
            jewels.emplace(c);
        }

        for (char c : S) {
            if (jewels.count(c) != 0)
            {
                jewelCount++;
            }
        }

        return jewelCount;
    }
}