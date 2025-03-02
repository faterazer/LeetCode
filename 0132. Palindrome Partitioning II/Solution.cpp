#include <climits>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int minCut(string s)
    {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, 1));
        for (int j = 1; j < n; ++j)
            for (int i = 0; i < j; ++i)
                dp[i][j] = (s[i] == s[j] && (j - i < 2 || dp[i + 1][j - 1]));

        vector<int> f(n, INT_MAX);
        for (int j = 0; j < n; ++j) {
            if (dp[0][j]) {
                f[j] = 1;
                continue;
            }
            for (int i = 1; i <= j; ++i)
                if (dp[i][j] && f[i - 1] != INT_MAX)
                    f[j] = min(f[j], f[i - 1] + 1);
        }
        return f.back() - 1;
    }
};
