# Write a function that takes:
# 1) A list of unsorted scores
# 3) The highest possible score in the game

# And returns a sorted list of scores in O(N) time

unsorted_scores = [37, 89, 41, 65, 91, 53]
highest_possible_score = 100

# Should return [91, 89, 65, 53, 41, 37]


# SOLUTION

def sort_scores(unsorted_scores, highest_possible_score):
    score_counts = [0] * highest_possible_score
    sorted_scores = []

    for score in unsorted_scores:
        score_counts[score] += 1

    for i in range(len(score_counts) - 1, -1, -1):
        while score_counts[i] > 0:
            sorted_scores.append(i)
            score_counts[i] -= 1

    return sorted_scores


# TESTS

assert(sort_scores(unsorted_scores, highest_possible_score) == [91, 89, 65, 53, 41, 37])
