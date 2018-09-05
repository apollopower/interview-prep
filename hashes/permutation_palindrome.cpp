bool hasPalindromePermutation(const string& str)
{
    // check if any permutation of the input is a palindrome
    map<char, int> letter_count;
    int odds_allowed = 1;
    
    for (size_t i = 0; i < str.length(); i++)
    {
        if (letter_count.find(str[i]) != letter_count.end())
        {
            letter_count[str[i]]++;
        }
        else
        {
            letter_count[str[i]] = 1;
        }
    }
    
    map<char, int>::iterator it;
    for (it = letter_count.begin(); it != letter_count.end(); it++)
    {
        if (it->second % 2 != 0)
        {
            odds_allowed--;
        }
    }
    
    if (odds_allowed < 0)
    {
        return false;
    }
    else
    {
        return true;
    }
    
}


// CLEANER SOLUTION:

bool hasPalindromePermutation(const string& str)
{
    // Track characters we've seen an odd number of times:
    unordered_set<char> unpairedChars;
    
    for (char c : str)
    {
        if (unpairedChars.find(c) != unpairedCharacters.end())
        {
            // We saw it before, meaning the count is even.
            // Let's erase our record of this char
            unpairedChars.erase(c);
        }
        else
        {
            // We have not seen it (or at an odd number
            // count), so we add it to our set
            unpairedChars.insert(c);
        }
    }
    
    // Our unpairedChars set should have AT MOST one character in
    // it. Here we return that boolean check:
    return unpairedChars <= 1;
}