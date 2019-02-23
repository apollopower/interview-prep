// For a given vector, return a vector that represents it in digits, +1;

// Input => [1,2,3]
// Output => [1,2,4]

// Input => [9,9,9]
// Output => [1,0,0,0]

vector<int> plusOne(vector<int> digits)
{
    for (int i = digits.size() - 1; i >= 0; i--)
    {
        if (digits[i] == 9)
        {
            digits[i] = 0;
        }
        else
        {
            digits[i]++;
            return digits;
        }

        digits[0] = 1;
        digits.push_back(0);

        return digits;
    }
}