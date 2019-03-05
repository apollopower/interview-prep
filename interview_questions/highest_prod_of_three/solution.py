# Given a list of integers, return the highest possible product of
# three integers


# SOLUTION

def highest_prod_of_three(num_list):
    if len(num_list) < 3:
        raise ValueError("Not enough values in list")

    highest_two_prod = num_list[0] * num_list[1]
    highest_three_prod = num_list[0] * num_list[1] * num_list[2]

    for i in range(2, len(num_list):
            current_num = num_list[i]
            # need to continue this one later... 
