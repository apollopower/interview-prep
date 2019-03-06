# What does Binary Search in Python look like?

# We are given a sorted list of numbers:
nums = [1, 2, 3, 4, 5, 6, 7, 8, 9]

# Our goal is simple: write binary search to return the index of 
# a specific number in the sorted list

# Lets begin our implementation:
def binary_search(nums, target_value):
    # First, we need to define the floor and ceiling with binary
    # search. These are our "walls", where we are looking at everything
    # in between them. 

    # To start, our floor and ceiling includes the entire list:

    floor = -1 # right before 0, first index
    ceiling = len(nums) # right after the last index

    # We run this loop until both floor and ceiling converge:
    while floor + 1 < ceiling:
        # Now to define our target index. This will be the middle
        # index between our floor and ceiling
        # 1) Get the distance between both floor and ceiling
        distance = ceiling - floor
        # 2) Find the halfway point in the distance:
        halfway = distance // 2 # double '/' returns an integer
        # 3) Now add the halfway distance to the floor, to get us our
        # target:
        target_idx = floor + halfway

        # If the number at the target_idx is our target value,
        # we found it! Return the index
        if nums[target_idx] == target_value:
            return target_idx
        # If the number at target_idx is GREATER than our target value,
        # we cut our list in half to all the numbers smaller than our guessed
        # number. We do this by setting the ceiling to our target_idx
        elif nums[target_idx] > target_value:
            ceiling = target_idx
        # If the number is SMALLER, we know we need to search the right side of
        # our current list, so we set the floor equal to our target_idx
        else:
            floor = target_idx

    # If our floor and ceiling merge, it means we did not find the number! We can
    # return an error saying that the target_value is not in the given list
    raise ValueError("Target Value does not exist in given list")


# TESTS
assert(binary_search(nums, 3) == 2)
assert(binary_search(nums, 1) == 0)