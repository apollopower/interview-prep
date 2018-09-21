#include <iostream>
#include <vector>

using namespace std;

vector<int> productOfOtherNums(vector<int> nums)
{
    // Since we are looking for products of OTHER numbers, we need to
    // make sure the array is not of size 1 or 0:
    if (nums.size() < 2)
    {
        throw invalid_argument("Vector needs to have more than 1 element!");
    }

    // Initializing our products vector, which we will return in the end:
    vector<int> products;

    // prevProducts keeps track of the product of indexes before a given index
    // we will be iterating over
    int prevProduct = 1;

    // First pass: insert product of all numbers BEFORE given index
    for (int i = 0; i < nums.size(); i++)
    {
        // push the prevProduct in products, which associates to the current
        // number's position in nums
        products.push_back(prevProduct);
        // Now we multiply our prevProduct by the current number
        prevProduct *= nums[i];
    }

    // Great! Now our products array keeps track of all products BEFORE the
    // given index. We need to do the same loop, but going backwards for
    // every product AFTER a given index. For this we reset prevProduct to 1

    prevProduct = 1;

    for (int i = nums.size() - 1; i > -1; i--)
    {
        // Values are already inside product, we just multiply the current
        // ones with prevProduct
        products[i] *= prevProduct;
        // Just like before, keep track of new prevProduct
        prevProduct *= nums[i];
    }

    return products; // done!
}

// To track all products of other numbers in an array/vector, we are taking:
// O(n) Time
// O(n) Space