#include <limits.h>

#define max(a, b) ((a > b) ? (a) : (b))
#define min(a, b) ((a < b) ? (a) : (b))

/*
    Solution.md
    Approach 2: One pass
    Time complexity: O(n)
    Space complexity: O(1)
*/
int maxProfit_MK1(int *prices, int pricesSize)
{
    int max_profit = 0, min_price = INT_MAX;
    for (int i = 0; i < pricesSize; i++)
    {
        min_price = min(min_price, prices[i]);
        max_profit = max(max_profit, prices[i] - min_price);
    }
    return max_profit;
}

/*
    My solution. Time complexity: O(n). Space complexity: O(1).
    Calculate the difference array of prices. Ex: For [7, 1, 5, 3, 6, 4], the difference array
    of prices is [0, -6, 4, -2, 3, -2], and then the problem converts to find the maximum subarray.
    You can read Solution.md of Problem 53. Maximum Subarray to understand details.
*/
int maxProfit_MK2(int *prices, int pricesSize)
{
    int max_profit = 0, cur_profit = 0;
    for (int i = 1; i < pricesSize; i++) {
        int diff = prices[i] - prices[i - 1];
        if (cur_profit < 0)
            cur_profit = diff;
        else
            cur_profit += diff;
        max_profit = max(max_profit, cur_profit);
    }
    return max_profit;
}
