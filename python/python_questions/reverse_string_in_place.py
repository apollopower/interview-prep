def reverse_string_in_place(str_list):

  left = 0
  right = len(str_list) - 1

  while left < right:
    str_list[left], str_list[right] = str_list[right], str_list[left]

    left += 1
    right -= 1
  
  return str_list


print(reverse_string_in_place(['j','o','n','a','s']))