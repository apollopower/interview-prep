#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

vector<vector<int> > pairsWithSpecificDifference(vector<int> arr, int k)
{
    vector<vector<int> > result;
    unordered_set<int> nums1;

    for (int i = 0; i < arr.size(); i++)
    {
        nums1.insert(arr[i]);
    }

    for (int i = 0; i < arr.size(); i++)
    {
        if (nums1.find(arr[i] + k) != nums1.end())
        {
            vector<int> numPair;
            numPair.push_back(arr[i] + k);
            numPair.push_back(arr[i]);

            result.push_back(numPair);
        }
    }

    return result;
}

int main()
{
    vector<int> arr{0, -1, -2, 2, 1};
    int k = 1;

    vector<vector<int> > result = pairsWithSpecificDifference(arr, k);

    for (auto vec : result)
    {
        for (int num : vec)
        {
            cout << num << " ";
        }
        cout << endl;
    }
}