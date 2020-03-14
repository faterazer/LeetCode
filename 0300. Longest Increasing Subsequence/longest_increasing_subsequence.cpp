#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
    int lengthOfLIS_MK1(vector<int> &nums); // Dynamic Programming
    int lengthOfLIS(vector<int> &nums);
};

// Dynamic Programming
// Time Complexity: O(n^2)
// Space complexity: O(n)
int Solution::lengthOfLIS_MK1(vector<int> &nums)
{
    if (nums.empty())
        return 0;
    vector<int> dp(nums.size(), 0);
    for (size_t i = 0; i < nums.size(); i++) {
        dp[i] = 1;
        for (size_t j = 0; j < i; j++) {
            if (nums[j] < nums[i])
                dp[i] = max(dp[j] + 1, dp[i]);
        }
    }
    return *max_element(dp.begin(), dp.end());
}

// Dynamic Programming with Binary Search
// Time Complexity: O(nlgn)
// Space Complexity: O(n)
int Solution::lengthOfLIS(vector<int> &nums)
{
    vector<int> dp;
    for (const int &num : nums) {
        auto it = lower_bound(dp.begin(), dp.end(), num);
        if (it == dp.end())
            dp.emplace_back(num);
        else
            *it = num;
    }
    return dp.size();
}
