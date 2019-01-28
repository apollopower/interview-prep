# Write a function that takes in a number, n, and returns the
# nth fibbonaci number:

def nth_fibbonaci(n):
    if n == 1:
        return 0
    elif n == 2:
        return 1

    fibs = [0, 1]

    i = 2
    while i < n:
        fibs.append(fibs[-2] +fibs[-1])
        i += 1
    
    return fibs[-1]

# Fibs Test
print("5th Fib = {}".format(nth_fibbonaci(5)))
