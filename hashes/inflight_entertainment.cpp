bool canTwoMoviesFillFlight(const vector<int>& movieLengths, int flightLength)
{
    // We use an UNORDERED SET (which only needs one value) for constant lookup 
    // of any needed time.
    unordered_set<int> cache;
    
    for (int movieLength : movieLengths)
    {   

        cache.find(movieLength);
        if (cache.find(movieLength) != cache.end())
        {
            return true;
        }
        else
        {
            int neededTime = flightLength - movieLength;
            cache.insert(neededTime);   
        }
    }

    return false;
}


// Using hash-based data structures, like unordered maps or unordered sets,
// is so common in coding challenge solutions, it should always be your
// first thought.