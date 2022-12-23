#include <bitset>
#include <numeric>
#include <vector>
using namespace std;

class Solution {
public:
    int maxScore(vector<int>& nums)
    {
        int n = nums.size();
        vector<int> dp(1 << n, 0);
        vector<vector<int>> gcd_tmp(n, vector<int>(n));
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++)
                gcd_tmp[i][j] = gcd(nums[i], nums[j]);

        constexpr int size = sizeof(size_t) * 8;
        for (size_t s = 1; s < dp.size(); s++) {
            int cnt = bitset<size>(s).count();
            if (cnt & 1)
                continue;

            for (int i = 0; i < n; i++)
                if ((s >> i) & 1)
                    for (int j = i + 1; j < n; j++)
                        if ((s >> j) & 1)
                            dp[s] = max(dp[s], dp[s ^ (1 << i) ^ (1 << j)] + cnt / 2 * gcd_tmp[i][j]);
        }
        return dp.back();
    }
};
