# Implement a time-efficient solution to finding the Nth fibonacci number


# SOLUTION

# This is a dynamic programming problem. We can take a recurisve approach to
# reach the base cases of a fibonacci sequence, and keep adding up our results

# We will use a cache to keep track of which fibonacci numbers we have already calculated,
# saving us a lot of computer time at the cost of space


# First, the function to determine our cache

def create_fib_cache(N):
    cache = [None] * (N + 2) # Each index stored the nth fib result
    # base case, fib 0 is 0 and fib 1 is 1
    cache[0], cache[1] = 0, 1
    return cache

# Now our recursice solution. It will take the number to compute, along with the cache
def recursive_fib(N, cache):
    if cache[N] is None:
        cache[N] = recursive_fib(N - 1, cache) + recursive_fib(N - 2, cache)
    elif cache[N] == 0:
        return 0
    elif cache[N] == 1:
        return 1
    # Once we reach the end, return the fib number for N
    return cache[N]



# TEST

N = 45
cache = create_fib_cache(N)

print(recursive_fib(N, cache))


# COMPLEXITY
# Time: O(N), our recurisve solution does a "depth-first" dive into the tree of recursive calls,
# and not repeating previous calculations (thanks to our cache)

# Space: O(N), we are caching our results depending on the size of input
