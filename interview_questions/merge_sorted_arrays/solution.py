# Given two sorted arrays, right a function that can merge them both together
# in O(N) time


# SOLUTION

arr1 = [3, 4, 6, 10, 11, 15, 9000]
arr2 = [1, 5, 8, 12, 14, 19]

def merge_sorted_arrays(arr1, arr2):
  # 1) get length of the longest array
  if len(arr1) > len(arr2):
    longest_len = len(arr1)
  else:
    longest_len = len(arr2)
  
  # 2) Create new merged array
  merged = []

  # 3) indexes representing their arrays
  i = 0 # arr1
  j = 0 # arr2

  # 4) Loop while we still have not iterated throught both arrays. we use the size of the longest array to run this:
  while i < longest_len or j < longest_len:
    if i == len(arr1):
      # we have looped through arr2, we can just add remaining values of arr2
      while j < longest_len:
        merged.append(arr2[j])
        j += 1
      return merged
    
    elif j == len(arr2):
      while i < longest_len:
        merged.append(arr1[i])
        i += 1
      return merged

    elif arr1[i] < arr2[j]:
      merged.append(arr1[i])
      i += 1
    
    else:
      merged.append(arr2[j])
      j += 1
  
  return merged

