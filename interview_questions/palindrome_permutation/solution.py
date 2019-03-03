# Write a function to check if a string is a permutation of a palindrome:

# Ex: "civic" => True
#     "ivicc" => True
#     "civil" => False


# SOLUTION

def palindrome_permutation(string):
    # The trick to this problem is knowing how palindromes work. For a 
    # a string to be a palindrome, all of its containing characters need
    # to occur an even amount of times, with the exception of one character
    # that can appear an odd amount of times.

    # The best way to keep track of characters will be with an unordered set,
    # which lets us know when we have seen a character before.
    char_set = set()
    # Now we iterate, adding and removing a char as necessary
    for char in string:
        if char in char_set:
            char_set.remove(char)
        else:
            char_set.add(char)
    # Finally, we check the size of the char_set. If it is has more than
    # one item inside it, the string is not a palindrome
    return len(char_set) < 2

# TESTS

assert(palindrome_permutation("ivcci") == True)
assert(palindrome_permutation("jonas") == False)

# COMPLEXITY

# Time => O(N), we do this in one pass of the string

# Space => O(N), we create a set who's size is dependent on the size of the
# input string
