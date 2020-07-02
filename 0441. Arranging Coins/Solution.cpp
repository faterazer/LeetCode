#include <cmath>

class Solution
{
public:
    int arrangeCoins(int n);
};

int Solution::arrangeCoins(int n)
{
    return sqrt(2) * sqrt(n + 0.125) - 0.5;
}
