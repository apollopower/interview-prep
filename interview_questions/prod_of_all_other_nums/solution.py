# Given a list of numbers, return a list whose items are the products of all numbers in the list
# except for the one at its index

# Example: [1, 7, 3, 4] => [84, 12, 28, 21]


# SOLUTION

def prod_of_all_other_nums(num_list):
    prod_list = [None] * len(num_list)
    
    current_prod = 1
    for i in range(len(num_list)):
            prod_list[i] = current_prod
            current_prod *= num_list[i]

    current_prod = 1
    for i in range(len(num_list) - 1, -1, -1):
            prod_list[i] *= current_prod
            current_prod *= num_list[i]

    return prod_list


# TESTS

assert(prod_of_all_other_nums([1, 7, 3, 4]) == [84, 12, 28, 21])
