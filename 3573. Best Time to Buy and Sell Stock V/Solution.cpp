#include <algorithm>
#include <array>
#include <limits>
#include <ranges>
#include <vector>
using namespace std;

class Solution {
public:
    long long maximumProfit(vector<int>& prices, int k)
    {
        constexpr long long NEG_INF = numeric_limits<long long>::min() / 2;
        vector<array<long long, 3>> dp(k + 2, { 0, NEG_INF, NEG_INF });
        for (int p : prices) {
            for (int i = k + 1; i > 0; --i) {
                dp[i][1] = max(dp[i][1], dp[i][0] - p);
                dp[i][2] = max(dp[i][2], dp[i][0] + p);
                dp[i][0] = ranges::max({ dp[i][0], dp[i - 1][1] + p, dp[i - 1][2] - p });
            }
        }
        return dp[k + 1][0];
    }
};
