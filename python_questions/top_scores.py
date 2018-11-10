# Given a list of unsorted scores and the highest possible score,
# sort the given stores faster than O(lgN) time. There are no possible
# negative scores


# Answer:

# In theory, given only an unsorted array (or list in this case), the
# fastest time to sort the scores WOULD BE O(lgN). However, this is a special case:

# We are given two additional pieces of information:
# 1 - There is a highest possible score, which is provided
# 2 - There can be no negative scores.

# With this, we know the possible range of scores would be from (0..HIGHEST_POSSIBLE_SCORE)

# This is key to being able to sort faster than O(lgN) time! It lets us use "count sort" and
# sort everthing in linear time, O(N). 

# We create a list where we use the indexes to represent scores, and we store how many times 
# a score appears based on its index. From there, we can loop backwards through the list,
# and insert a given scores as many times as it appears. We know have a sorted list in O(N) time!

def sort_scores(unsorted_scores, highest_possible_score):

    # Sort the scores in O(n) time
    sorted_scores = []
    
    score_tracker = [0] * (highest_possible_score + 1)
    
    for score in unsorted_scores:
        score_tracker[score] += 1
    
    i = highest_possible_score
    
    while i >= 0:
        while score_tracker[i] > 0:
            sorted_scores.append(i)
            score_tracker[i] -= 1
            
        i -= 1
    
    return sorted_scores
