// Given a list of unordered highscores, as well as a constant int, maxscore,
// which represent the highest possible score in the game, write a function
// that *sorts the highscores from highest to lowest*.

// The Catch? It has to be faster than O(nlgn) time.
// So no (mergesort or quicksort)

// ...

// We can solve this using *counting sort*, mapping a vector's indexes
// to a score, and its value to how often it appears in unorderedScores.
// The KEY reason we can do this is because we have a reference point of
// the MAXIMUM POSSIBLE SCORE. Without it, we would NOT be able to solve
// this in O(n) time since we would not know the bounds of what needs to
// be sorted.

#include <vector>

vector<int> highScores(vector<int>unorderedScores, int highestPossibleScore)
{
    vector<int> scoreCount(highestPossibleScore + 1); // keep track of scores
    vector<int> highScores; // What we will return

    for (int score : unorderedScores)
    {
        scoreCount[score]++;
    }

    // Now we have a vector that maps all indexes to scores, and their values
    // to how often they appear. We can iterate, back to front, the scoreCount
    // vector, pushing each score as many times it appears into our highScores
    // answer vector

    for (int i = scoreCount.size() -1; i > -1; i--)
    {
        if (scoreCount[i] > 0)
        {
            while (scoreCount[i] > 0)
            {
                highScores.push_back(i);
                scoreCount[i]--;
            }
        }
    }

    return highScores;
}

// Running time: O(n)
// Space: O(n)