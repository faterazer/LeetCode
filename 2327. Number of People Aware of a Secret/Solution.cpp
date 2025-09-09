#include <deque>
#include <vector>
using namespace std;

class Solution {
public:
    // 动态规划
    int peopleAwareOfSecret_MK1(int n, int delay, int forget)
    {
        constexpr int MOD = 1e9 + 7;
        vector<long long> dp(n);
        dp[0] = 1;
        int slide_sum = 0;
        for (int i = 1; i < n; ++i) {
            if (i >= delay)
                slide_sum = (slide_sum + dp[i - delay]) % MOD;
            if (i >= forget)
                slide_sum = (slide_sum - dp[i - forget] + MOD) % MOD;
            dp[i] = slide_sum;
        }

        int ans = 0;
        for (int i = n - forget; i < n; ++i)
            ans = (ans + dp[i]) % MOD;
        return ans;
    }

    // 前缀和
    int peopleAwareOfSecret(int n, int delay, int forget)
    {
        constexpr int MOD = 1e9 + 7;
        vector<int> pre_sum(n + 1);
        pre_sum[0] = 0;
        pre_sum[1] = 1;
        for (int i = 2; i <= n; ++i) {
            int known = (pre_sum[max(0, i - delay)] - pre_sum[max(0, i - forget)]) % MOD;
            pre_sum[i] = (pre_sum[i - 1] + known) % MOD;
        }
        return (pre_sum[n] - pre_sum[max(0, n - forget)] + MOD) % MOD;
    }
};
