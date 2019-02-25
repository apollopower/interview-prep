# Given an array of integers where each value 1 <= x <= len(array),
# write a function that finds all duplicates in the array

# Example:
# dups([1,2,3]) => []
# dups([1,2,2]) => [2]
# dups([2,1,2,1]) => [1,2]

# Solution:
def duplicates(arr):
    dups = []
    passed_nums = set()
    for num in arr:
        if num in passed_nums:
            dups.append(num)
        else:
            passed_nums.add(num)
    return dups


# Tests
assert(duplicates([1,2,3]) == [])
assert(duplicates([1,2,2]) == [2])
assert(duplicates([2,1,2,1]) == [2,1])