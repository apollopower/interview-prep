# Implement your own version of the dot product operation. Use Numpy's dot product
# method to verify your solution


# SOLUTION

# This solution works currently only for vectors and not 2D matrices

def dot_product(vec1, vec2):
    return sum(i * j for i, j in zip(vec1, vec2))


# TEST

import numpy as np

vec1 = [1, 2, 3]
vec2 = [4, 5, 6]

assert(dot_product(vec1, vec2) == np.dot(vec1, vec2))
