# Write a function that checks if a given string is a 
# permutation of a palindrome.

# Do this in O(n) time



# ANSWER

# By using an "unordered set", we can keep track of letter pairs.
# Palindromes will always have letters paired, with sometimes the
# exeption of one letter.

# Space time complexity:

# Time => O(n), we only need to check all the characters in the string
# Space => O(k), because the size of the set is fixed to the range of ASCII
# characters available (128)

def permutation_palindrom(string):
  char_set = set()

  for char in string:
    if char not in char_set:
      char_set.add(char)
    else:
      char_set.remove(char)

  return len(char_set) < 2