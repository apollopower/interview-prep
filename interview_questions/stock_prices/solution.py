# Write an efficient function that takes stock_prices and returns the
# best profit I could have made from one purchase and one sale of one
# share of stock yesterday.

# stock_prices = [10, 7, 5, 8, 11, 9]

# get_max_profit(stock_prices)
# Returns 6 (buying for $5 and selling for $11)


# SOLUTION
def get_max_profit(stock_prices):
    buying_price = stock_prices[0]
    selling_price = stock_prices[1]
    max_profit = selling_price - buying_price

    for i in range(1, len(stock_prices)):
        current_price = stock_prices[i]
        current_profit = current_price - buying_price

        if current_profit > max_profit:
            max_profit = current_profit

        if current_price < buying_price:
            buying_price = current_price

    return max_profit


# TESTS
assert(get_max_profit([10, 7, 5, 8, 11, 9]) == 6)


# COMPLEXITY
# Time => O(N), linear
# Space => O(1), constant. We only use fixed amount of variables 
