#include <iostream>
#include <vector>

using namespace std;

int partition(vector<int> arr, int low, int high)
{

    int pivotIndex;
    int firstHigh;  // divider position for the first element

    pivotIndex = high;
    firstHigh = low;

    for (int i = low; i < high; i++)
    {
        if (arr[i] < arr[pivotIndex])
        {
            swap(&arr[i], &arr[firstHigh]);
            firstHigh++;
        }
    }
    swap(&arr[pivotIndex], &arr[firstHigh]);

    return firstHigh;
}

vector<int> quicksort(vector<int> arr, int low, int high)
{
    int pivotIndex;

    if ((high - 1) > 0)
    {
        pivotIndex = partition(arr, low, high);
        quicksort(arr, low, pivotIndex - 1);
        quicksort(arr, pivotIndex + 1, high);
    }
}
