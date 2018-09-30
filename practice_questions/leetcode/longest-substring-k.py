# Given a string, find the length of the longest substring T that contains at
# most K unique characters:

# Input => s = "eceba", k = 2
# Output => 3 ("ece" is the longest subtring with 2 unique characters)

def longestSubstringKDistinct(s, k):
    charCount = {}
    low , rect = 0, 0
    for i, c in enumerate(s):
        d[c] = i
        
        if len(charCount) > k:
            low = min(charCount.values())
            del charCount[s[low]]
            low += 1
        
        ret = max(i - low + 1, ret)
        
    return ret