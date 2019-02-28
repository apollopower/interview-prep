# Write a function that takes a string and reverses it, in-place
# This means we are not using any addition memory for a new string


# SOLUTION

def reverse_inplace(string):
    # Strings are immuatable in Python. We need to begin with a list!
    string_list = list(string)
    # Setting up indexes that we will use for swapping
    i = 0 # Left char
    j = len(string) - 1 # Right char
    # Now begin loop. As long as both values do not cross, we keep swapping values
    # and moving them
    while i < j:
        string_list[i], string_list[j] = string_list[j], string_list[i]
        i += 1
        j -= 1
    # Now return our modified string
    return "".join(string_list)

# TESTS
assert(reverse_inplace("jonas") == "sanoj")
assert(reverse_inplace("bobo") == "obob")

# COMPLEXITY
# Time => O(N)
# Space => O(1) (technically, O(N) since we have to transform string into list, but for 
# the purpose of the exercise, this is correct)