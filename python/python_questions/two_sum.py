# Classic Two Sum problem. Keep track of of difference values through a hashmap
# (dictionary in Python)

# O(n) time and O(n) space!

def two_sum(arr, sum_val):
    difference = {}

    for idx, val in enumerate(arr):
        if val in difference:
            return [idx, difference[val]]
        else:
            difference[sum_val - val] = idx
    print("No....")

print(two_sum([1,2,3], 5))