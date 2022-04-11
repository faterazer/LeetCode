#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    bool isMatch(string s, string p)
    {
        int sn = s.size(), pn = p.size();
        vector<vector<int>> dp(sn + 1, vector<int>(pn + 1, 0));
        dp[0][0] = 1;
        for (int i = 0; i <= sn; ++i) {
            for (int j = 1; j <= pn; ++j) {
                if (i > 0 && (s[i - 1] == p[j - 1] || p[j - 1] == '.'))
                    dp[i][j] = dp[i - 1][j - 1];
                else if (p[j - 1] == '*') {
                    dp[i][j] = dp[i][j - 2];
                    if (i > 0 && (p[j - 2] == s[i - 1] || p[j - 2] == '.'))
                        dp[i][j] |= dp[i - 1][j];
                }
            }
        }
        return dp[sn][pn];
    }
};
