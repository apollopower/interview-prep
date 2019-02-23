# Assume you have access to a function toss_biased() which returns 0 or 1 with
# a probability that's not 50-50 (but also not 0-100 or 100-0). You do not know
# the bias of the coin.

# Write a function to simulate an unbiased coin toss.

from random import random

BIAS = 0.66

def toss_biased():
    return random() > BIAS


# Say, the probability of getting heads, H, is P. Thus we can deduce that tails, T,
# would be equal to 1 - P. We can compute two consectuive coin flips as follows:

# HH: P * P
# HT: P * (1 - P)
# TH: (1 - P) * P
# TT: (1 - P) * (1 - P)

# Since multiplication is commutative, we find that flipping heads and then tails
# has the same probability of flipping tails, then heads


def toss_fair():
    t1, t2 = toss_biased(), toss_biased()

    if t1 and not t2:
        return True
    elif not t1 and t2:
        return False
    else:
        return toss_fair()


# Test to prove our probabilites match close to 50/50
from collections import defaultdict

c = defaultdict(int)
for i in range(10000):
    c[toss_fair()] += 1

print(c)