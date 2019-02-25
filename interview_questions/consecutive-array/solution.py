#  Given an unsorted array, find the length of the
# longest sequence of consecutive numbers in the array

# Examples:
# consecutive([4,2,1,6,5]) => 3, ([4,5,6])
# consecutive([5,5,3,1]) => 1, ([1], [3], or [5])

# Solution
def consecutive(arr):
    longest_count = 0
    num_set = set()

    for num in arr:
        if num not in num_set:
            num_set.add(num)
    
    for num in arr:
        current_count = 0
        consecutive_num = num
        while consecutive_num in num_set:
            current_count += 1
            consecutive_num += 1
        
        if current_count > longest_count:
            longest_count = current_count
    
    return longest_count


# Tests
assert(consecutive([4,2,1,6,5]) == 3)
assert(consecutive([5,5,3,1]) == 1)
        

# Time Complexity => O(N)
# Space Complexity => O(N)