#include <algorithm>
#include <vector>
using namespace std;


class Solution {
public:
    int maxProfit_MK1(vector<int>& prices); // Solution.md: Approach 2: One pass
    int maxProfit_MK2(vector<int>& prices);
};

// Solution.md
// Approach 2: One pass
// Time complexity: O(n)
// Space complexity: O(1)
int Solution::maxProfit_MK1(vector<int> &prices)
{
    if (prices.empty())
        return 0;
    int max = 0, min = prices[0];
    for (size_t i = 1; i < prices.size(); i++) {
        if (prices[i] < min)
            min = prices[i];
        else
            max = std::max(max, prices[i] - min);
    }
    return max;
}

// My solution. Time complexity: O(n). Space complexity: O(1).
// Calculate the difference array of prices. Ex: For [7, 1, 5, 3, 6, 4], the difference array
// of prices is [0, -6, 4, -2, 3, -2], and then the problem converts to find the maximum subarray.
// You can read Solution.md of Problem 53. Maximum Subarray to understand details.
int Solution::maxProfit_MK2(vector<int> &prices)
{
    int max = 0, curr = 0;
    for (size_t i = 1; i < prices.size(); i++) {
        int diff = prices[i] - prices[i - 1];
        if (curr < 0)
            curr = diff;
        else
            curr += diff;
        max = std::max(max, curr);
    }
    return max;
}
