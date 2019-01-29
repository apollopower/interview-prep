# Implement an algorithm to determine if a string has all unique characters.
# What if you cannot use additional data structures?

def is_unique(string):
    pass

# ANSWER

# 1) Using a map

def is_unique(string):
    char_count = set()
    for c in string:
        if c in char_count:
            return False
        else:
            char_count.add(c) 

    return True

# Runs in O(n) time, takes O(n) space


# 2) Not using any additional data structures:

def is_unique2(string):
    for c1 in string:
        for c2 in string:
            if c1 == c2:
                return False
    return True

# Takes O(n) space, but runs in O(n^2) time
