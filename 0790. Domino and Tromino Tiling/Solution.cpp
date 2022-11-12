#include <algorithm>
using namespace std;

class Solution {
public:
    int numTilings(int n)
    {
        int P = 1e9 + 7;
        int dp[4] = { 1, 1, 2, 5 };
        if (n <= 3)
            return dp[n];
        for (int i = 4; i <= n; i++) {
            dp[0] = (2 * dp[3] % P + dp[1]) % P;
            dp[1] = dp[2];
            dp[2] = dp[3];
            dp[3] = dp[0];
        }
        return dp[3];
    }
};
