#include <vector>
using namespace std;

class Solution {
public:
    int dieSimulator(int n, vector<int>& rollMax)
    {
        int m = rollMax.size(), dp[n][m], s[n];
        for (int i = 0; i < m; i++)
            dp[0][i] = 1;
        s[0] = m;

        for (int i = 1; i < n; i++) {
            s[i] = 0;
            for (int j = 0; j < m; j++) {
                dp[i][j] = s[i - 1];
                if (i > rollMax[j])
                    dp[i][j] = dp[i][j] - s[i - rollMax[j] - 1] + dp[i - rollMax[j] - 1][j];
                else if (i == rollMax[j])
                    --dp[i][j];
                dp[i][j] = (dp[i][j] + MOD) % MOD;
                s[i] = (s[i] + dp[i][j]) % MOD;
            }
        }
        return s[n - 1];
    }

private:
    static constexpr long long MOD = 1e9 + 7;
};
