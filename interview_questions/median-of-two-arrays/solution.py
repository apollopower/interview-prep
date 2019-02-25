# Find the median of two sorted arrays

# Examples:
# arr1 = [1, 3, 5]
# arr2 = [2, 4, 6]
# median(arr1, arr2) => 3.5

# Solution:

import statistics

def median(arr1, arr2):
    med1 = statistics.median(arr1)
    med2 = statistics.median(arr2)
    return float((med1 + med2) / 2)


assert(median([1, 3, 5], [2, 4, 6]) == 3.5)
