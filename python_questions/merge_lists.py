# Merge Two Sorted lists

# The key to this problem is that the given lists are
# already sorted. We can just iterate through both
# at the same time, inserting the smallest value at a given
# time, and then checking the next value

# Space complexity => O(n), we are returning a newly merged list
# Time complextiy => O(n), we are iterating through each list only once

def merged_lists(list_1, list_2):

  merged_list = []

  if len(list_1) > len(list_2):
    largest_length = len(list_1)
  else:
    largest_length = len(list_2)
  
  i = 0 # list_1
  j = 0 # list_2
  while i < largest_length or j < largest_length:
    if i == len(list_1):
      # insert remaining valus of list_2
      # and return merged_list
      while j < largest_length:
        merged_list.append(list_2[j])
        j += 1
      
      return merged_list
    elif j == len(list_2):
      # insert remaining values of list_1
      # and return merged_list
      while i < largest_length:
        merged_list.append(list_1[i])
        i += 1
      
      return merged_list
    elif list_1[i] < list_2[j]:
      merged_list.append(list_1[i])
      i += 1
    else:
      merged_list.append(list_2[j])
      j += 1
  
  return merged_list

list_1 = [1,3,5,7,10,12]
list_2 = [2,4,6,8,9]

print(merged_lists(list_1, list_2))