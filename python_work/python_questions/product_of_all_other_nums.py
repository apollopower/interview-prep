# Given a list of nums, return a list
# where each num is the product of all
# nums of the input list, except for the
# one at its given position

def product_of_other_nums(nums):

  products = [1] * len(nums)
  current_prod = 1
  
  for i in range(1, len(nums)):
    products[i] = current_prod
    current_prod *= nums[i]
  
  current_prod = 1
  for i in range(len(nums) - 1, -1, -1):
    products[i] *= current_prod
    current_prod *= nums[i]
  
  print(products)


nums = [1, 2, 6, 5, 9]

product_of_other_nums(nums)