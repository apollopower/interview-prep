#include <iostream>
#include <vector>

using namespace std;


// BRUTE FORCE APPROACH
int getMaxProfit(const vector<int>& stockPrices)
{
  int max_profit = 0;
  for (size_t rightIdx = stockPrices.size() - 1; rightIdx > 0; --rightIdx)
  {
    for (size_t leftIdx = 0; leftIdx < rightIdx; ++leftIdx)
    {
      if (stockPrices[rightIdx] - stockPrices[leftIdx] > max_profit)
      {
        max_profit = stockPrices[rightIdx] - stockPrices[leftIdx];
      }
    }
  }
  return max_profit;
}


// GREEDY APPROACH O(n) time

int getMaxProfit(const vector<int>& stockPrices)
{
    if (stockPrices.size() < 2)
    {
        throw invalid_argument("Getting a profit requires at least 2 prices\n");
    }
    
    int minPrice = stockPrices[0];
    int maxProfit = stockPrices[1] - stockPrices[0];
  
    for (size_t i = 1; i < stockPrices.size(); ++i)
    {
        int currentPrice = stockPrices[i];
      
        // See what our profit would be if we bought at the min price
        // and sold at the current price:
        int potentialProfit = currentPrice - minPrice;
      
        // update maxProfit if we can do better:
        maxProfit = max(maxProfit, potentialProfit);
        
        // ensure minPrice is the lowest price we've seen so far:
        minPrice = min(minPrice, currentPrice);
    }
  
  return maxProfit;
}

int main() {
  vector<int> stockPrices{10, 7, 5, 8, 11, 9};

  cout << getMaxProfit(stockPrices) << endl;
  // returns 6 (buying for $5 and selling for $11)
}