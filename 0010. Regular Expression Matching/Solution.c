#include <stdbool.h>
#include <string.h>

bool isMatch(char* s, char* p)
{
    int sn = strlen(s), pn = strlen(p);
    int dp[sn + 1][pn + 1];
    memset(dp, 0, sizeof(int) * (sn + 1) * (pn + 1));
    dp[0][0] = 1;
    for (int i = 0; i <= sn; ++i) {
        for (int j = 1; j <= pn; ++j) {
            if (i > 0 && (s[i - 1] == p[j - 1] || p[j - 1] == '.'))
                dp[i][j] = dp[i - 1][j - 1];
            else if (p[j - 1] == '*') {
                dp[i][j] = dp[i][j - 2];
                if (i > 0 && (s[i - 1] == p[j - 2] || p[j - 2] == '.'))
                    dp[i][j] |= dp[i - 1][j];
            }
        }
    }
    return dp[sn][pn];
}
