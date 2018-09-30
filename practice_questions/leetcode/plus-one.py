# Given an array of numbers, return an array that reprents the digit plus one of all
# the numbers in the input array:

# Input = [1,2,3]
# Output = [1,2,4] (input is equal to 123, which plus one is 124)

def plusOne(digits):
    answer = []
    strNums = ""
    for num in digits:
        strNums += str(num)
    
    intNums = int(strNums) + 1

    for num in str(intNums):
        answer.append(int(num))
    
    return answer