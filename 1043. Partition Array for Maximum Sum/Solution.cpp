#include <vector>
using namespace std;

class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k)
    {
        int n = arr.size();
        vector<int> dp(k, 0);
        for (int i = 1; i <= n; i++) {
            int max_val = 0, best = 0;
            for (int j = 1; j <= k && i - j >= 0; j++) {
                max_val = max(max_val, arr[i - j]);
                best = max(best, dp[(i - j) % k] + max_val * j);
            }
            dp[i % k] = best;
        }
        return dp[n % k];
    }
};
