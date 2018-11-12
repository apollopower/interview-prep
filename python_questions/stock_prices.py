# Given a list of stock prices throughout the course of a day, find the
# largest profit one can make from buying and selling.

# Running time should be better than O(N^2)



# ANSWER

# To do better than a brute force approach, we need to implement a greedy algorithm.
# This keeps track of the max profit that can be made as we iterate through the list of
# prices. 

# Runtime => O(N) 
# Space => O(1)

def get_max_profit(stock_prices):
  if len(stock_prices) < 2:
    raise ValueError("Need more than 2 stock prices to buy and sell")
  
  purchase_price = stock_prices[0]
  max_profit = stock_prices[0] - stock_prices[1]

  for current_time in range(1, len(stock_prices)):
    current_price = stock_prices[current_time]

    potential_profit = current_price - purchase_price

    max_profit = max(potential_profit, max_profit)

    purchase_price = min(current_price, purchase_price)
  
  return max_profit


stock_prices = [10, 7, 5, 8, 11, 9]

print(get_max_profit(stock_prices))