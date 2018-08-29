// Big O Notation:

// The language used to explain how long an algorithm would take
// to run

// We care about how quickly it grows relative to the input, as
// the input gets arbitrarily large.

// EXAMPLES

// O(1) runtime, "Constant Time":
void printFirstItem(const vector<int>& items) {
    std::cout << items[0] << endl;
}

// O(n) runtime, "Linear Time":
void printAllItems(const vector<int>& items) {
    for (int item : items) {
        cout << item << endl;
    }
}

// O(n^2) runtime, "Quadratic Time":
// *note the nested for loops*
void printAllPossibleOrderedPairs(const vector<int>& items) {
    for (int firstItem : item) {
        for (int secondItem: item) {
            cout << firstItem << ", " << secondItem << endl;
        }
    }
}


// N could be the actual input, or the size of the input
void sayHiNTimes(size_t n) {
    for (size_t i = 0; i < n; ++i) {
        cout << "Hi!" << endl;
    }
} // still O(n)

// We also drop constants. For example, while the function
// below still uses 2 loops, it can be described as O(2n):
void printAllItemsTwice(const vector<int>& items) {

    for(int item: items) {
        cout << item << endl;
    }

    for (int item: items) {
        cout << item << endl;
    }
} // Rememember, we drop the constants, so O(2n) really is
// O(2n)

// The point is that we're looking for the rate at which n
// gets larger. In the above example, while there are 2
// for-loops, larger vectors would only cause the runtime
// to increase at a linear rate


// DROPPING LESS SIGNIFACNT TERMS

// We care about the larger term that affects runtime, so for
// example:
void printAllNumbersThenAllPairSums(const vector<int>& numbers) {
    cout << "There are the numbers: " << endl;

    // 1 seperate loop for linear runtime, O(n)
    for (int number: numbers) {
        cout << number << endl;
    }

    // 2 nested loops for quadratic time, O(n^2)
    for (int firstNum: numbers) {
        for (int secondNum: numbers) {
            cout << (firstNum + secondNum) << endl;
        }
    }
} // Runtime is O(n + n^2), but we only care about the largest
// term, as that expresses the algorithm's complexity. Hence, we
// just describe it as O(n^2)


// ALWAYS THINK ABOUT THE WORST-CASE

// When thinking about runtimes, we want to express them as 
// "worst case scenarios", because the lowest possible performance
// point sets the benchmark for the algorithm

// An example:
bool contains(const vector<int>& haystack, int needle) {
    // loop checking if the haystack contains the needle...
    for (int n : haystack) {
        if (n == needle) {
            // found it! Return function
            return true;
        }
    }

    // we checked the whole thing, and didn't find the needle
    return false;
} // The needle could be the first item we encounter in our loop,
// which would then make that specific iteratino of the algorithm
// O(1), constant. Fantastic! But what if we don't find it? We
// search the entire haystack, making it the worst-case scenario.
// The worst-case is O(n), so thats what we use to describe it


// SPACE COMPLEXITY

// Sometimes we want to optimize for using less memoery instead of
// (or in addition to) using less time. Talking about memory cost,
// AKA "space complexity", is very similiar to talking about time
// cost.

// This function takes O(1) space, since we have a fixed number
// of variables:
void sayHiNTimes(size_t n) {
    for (size_t i = 0; i < n; ++i) {
        cout << "Hi!" << endl;
    }
} // O(n) runtime, but O(1) time


// This function takes O(n) space, since the size of the vector
// scales with the size of the input:
vector<string> vectorOfHiNTimes(size_t n) {
    vector<string> hiVector;
    for (size_t i = 0; i < n; ++i) {
        hiVector.push_back("Hi!");
    }
    return hiVector;
}

// Note that we don't include space taken by inputs:
int getLargestItem(const vector<int>& items) {
    int largest = numeric_limits<int>::min();
    for (int item: items) {
        if (item > largest) {
            largest = item;
        }
    }
    return largest;
} // This function takes constant space even through the input
// has n items

// Sometimes there's a tradeoff between saving time and saving space,
// so you have to decide which one you're optimizing for.

// You should develop the skill to see time and space optimizations,
// as well as the wisdom to judge if those optimizations are
// worthwhile.