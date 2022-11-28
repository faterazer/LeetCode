#include <vector>
using namespace std;

class Solution {
public:
    double largestSumOfAverages(vector<int>& nums, int k)
    {
        int n = nums.size();
        vector<double> pre_sum(n + 1, 0.0);
        for (size_t i = 1; i < pre_sum.size(); i++)
            pre_sum[i] = pre_sum[i - 1] + nums[i - 1];

        vector<double> dp(n + 1, 0.0);
        for (int i = 1; i <= n; i++)
            dp[i] = pre_sum[i] / i;

        for (int i = 2; i <= k; i++)
            for (int j = n; j >= i; j--)
                for (int w = 0; w < j; w++)
                    dp[j] = max(dp[j], dp[w] + (pre_sum[j] - pre_sum[w]) / (j - w));
        return dp[n];
    }
};
