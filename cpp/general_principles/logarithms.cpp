// Logarithms

// Logs come up in the time cost of binary search, which cuts
// the search space of an array/vector in half through every
// iteration:

using namespace std;

bool binarySearch(int target, const vector<int>& nums)
{
    // See if target appears in nums

    // We think of floorindex as leftmost edge of possible positions
    // of our target and ceilingIndex as the rightmost edge
    size_t floorIndex = 0;
    size_t ceilingIndex = nums.size();

    // if there isn't at least 1 index between floor and ceiling,
    // we've run out of guesses and the number must not be present.
    while (floorIndex < ceilingIndex) {

        // Find the index halfway between the floor and ceiling.
        // We use integer division, so we'll never get a "half
        // index"
        size_t distance = ceilingIndex - floorIndex;
        // Being very careful here with the mixed operation of
        // size_t and an int (int is positive so we're fine)
        size_t halfDistance = distance / 2;
        size_t guessIndex = floorIndex + halfDistance;

        int guessValue = nums[guessIndex];

        if (guessValue == target) {
            // We found it!
            return true;
        }
        else if (guessValue > target) {
            // Target is to the left, so move ceiling to the left
            ceilingIndex = guessIndex;
        }
        else {
            // Target is to the right, so move floor to the right
            floorIndex = guessIndex + 1;
        }
    }

    // We didn't find it...
    return false;
}

// The Runtime cost for binary search is O(log2n)


// Logarithms for Sorting

void mergeSort(vector<int>& vectorToSort)
{
    // BASE CASE: arrays/vectos with fewer than 2 elements are
    // sorted:
    if (vectorToSort.size() < 2) {
        return;
    }

    // STEP 1: divide the array in half
    // We use integer divion, so we'll never get "half index"
    size_t midIndex = vectorToSort.size() / 2;

    vector<int> left(vectorToSort.begin(), vectorToSort.being() + midIndex);
    vector<int> right(vectorToSort.begin() + midIndex, vectorToSort.end());

    // STEP 2: Sort each half (recursive call)
    mergeSort(left);
    mergeSort(right);

    // STEP 3: Merge the sorted halves
    size_t currentLeftIndex = 0;
    size_t currentRightIndex = 0;

    for (size_t currentSortedIndex = 0; currentSortedIndex < vectorToSort.size(); ++currentSortedIndex) {
        // sortedLeft's first element comes next
        // if it's less than sortedRight's first
        // element or if sortedRight is empty
        if (currentLeftIndex < left.size()
                && (currentRightIndex >= right.size()
                || left[currentLeftIndex] < right[currentRightIndex]))
        {
            vectorToSort[currentSortedIndex] = left[currentLeftIndex];
            ++currentLeftIndex;
        }
        else {
            vectorToSort[currentSortedIndex] = right[currentRightIndex];
            ++currentRightIndex; 
        }
    }
}