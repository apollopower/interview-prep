num_array = [5,2,7,5,9,7,3]

def get_even_array(arr):
    num_count = {}

    for num in arr:
        if num in num_count:
            num_count[num] += 1
        else:
            num_count[num] = 1

    return num_count


print(get_even_array(num_array))