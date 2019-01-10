def sum(val1, val2):
    val2 = 0
    newval = val1 + val2
    return newval

values = range(1, 11)
total = 0

import pdb; pdb.set_trace()

for val in values:
    val = sum(val, 1)
    total += val

assert total == 65