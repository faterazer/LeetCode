#include <vector>
using namespace std;


class Solution {
public:
    int rob_MK1(vector<int> &nums); // recursive + memo
    int rob_MK2(vector<int> &nums); // iterative
private:
    int rob(vector<int> &nums, int begin, vector<int> &memo);
};

// Recursive + memo
int Solution::rob_MK1(vector<int> &nums)
{
    vector<int> memo(nums.size(), -1);
    return rob(nums, 0, memo);
}

int Solution::rob(vector<int> &nums, int begin, vector<int> &memo)
{
    if (begin >= nums.size())
        return 0;
    if (memo[begin] > -1)
        return memo[begin];
    memo[begin] = max(nums[begin] + rob(nums, begin + 2, memo), rob(nums, begin + 1, memo));
    return memo[begin];
}

int Solution::rob_MK2(vector<int> &nums)
{
    int prev_max = 0, curr_max = 0, tmp;
    for (const auto &n : nums) {
        tmp = curr_max;
        curr_max = max(n + prev_max, curr_max);
        prev_max = tmp;
    }
    return curr_max;
}
