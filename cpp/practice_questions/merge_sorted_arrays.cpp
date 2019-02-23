// Given two SORTED arrays, merge them both together,
// while keeping the final array sorted.
// Try to do this in optimal space/time complexity.

// BREAKDOWN:

// Time:
// To create a sorted array, we will need to
// go through all values in our vectors, so the
// fastest time we can do is O(n).

// Space:
// Since we are CREATING a new merged array, space
// will depend on size of inputs, so this will take
// O(n) space.

// Approach:
// The key to this problem is that the arrays are already
// sorted. This makes our job straightforward. We can iterate
// through both arrays at the same time, keeping track of each
// of their indexes at a given time.

// We compare the values of both arrays at a given index. The smallest
// one we push into our result array. We increment the index for the array
// we found the smaller element, and repeat the process until we have covered
// all elements in both vectors.

// Things to keep in mind:
// 1- The arrays can have different sizes.
// 2- One (or both) of the arrays can be empty.
// 3- The arrays can share the same values.

#include <iostream>
#include <vector>

using namespace std;

// [2,3,6,8,9]
// [1,4,5,7,10,11]

// Merge Sorted Arrays
vector<int> mergeVectors(vector<int> vec1, vector<int> vec2)
{
  // If both vecs are empty:
  if (vec1.empty() && vec2.empty())
  {
    return {};
  }

  // vector that will return merged values
  vector<int> merged;

  // Longest vector will be used to keep
  // track of iteration
  int maxLength;

  if (vec1.size() > vec2.size())
  {
    maxLength = vec1.size();
  }
  else
  {
    maxLength = vec2.size();
  }


  // iterators: i -> vec1, j -> vec2
  int i = 0;
  int j = 0;
  while (i < maxLength || j < maxLength)
  {
    if (i == vec1.size())
    {
      // Insert remaining vec2 values and return
      // merged vector
      while (j < maxLength)
      {
        merged.push_back(vec2[j]);
        j++;
      }

      return merged;
    }
    else if (j == vec2.size())
    {
      // Insert remaining vec1 vals and return
      // merged vector
      while (i < maxLength)
      {
        merged.push_back(vec1[i]);
        i++;
      }

      return merged;
    }
    else
    {
      if (vec1[i] < vec2[j])
      {
        merged.push_back(vec1[i]);
        i++;
      }
      else if (vec2[j] < vec1[i])
      {
        merged.push_back(vec2[j]);
        j++;
      }
      else
      {
        // Both vals are equal. push both
        merged.push_back(vec1[i]);
        merged.push_back(vec2[j]);
        i++;
        j++;
      }

    }

  }

  return merged;
}
// Performance Summary:
// In short, we can merge sorted arrays in linear time
// and linear space, O(n). We check for all possible edge cases,
// ASSUMING the inputs will always be sorted.

// Execute our tests
int main()
{
  vector<int> vec1 {2,3,6,8,9};
  vector<int> vec2 {1,4,5,7,10,11};

  vector<int> merged = mergeVectors(vec1, vec2);

  for (int n : merged)
  {
    cout << n << " ";
  }
  printf("\n");
}