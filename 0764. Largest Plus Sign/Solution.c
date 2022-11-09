#include <math.h>
#include <string.h>

int orderOfLargestPlusSign(int n, int** mines, int minesSize, int* minesColSize)
{
    int dp[n][n];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            dp[i][j] = n;
    for (int i = 0; i < minesSize; i++)
        dp[mines[i][0]][mines[i][1]] = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0, k = n - 1, l = 0, r = 0, u = 0, d = 0; j < n; j++, k--) {
            dp[i][j] = fmin(dp[i][j], l = (dp[i][j] == 0 ? 0 : l + 1));
            dp[i][k] = fmin(dp[i][k], r = (dp[i][k] == 0 ? 0 : r + 1));
            dp[j][i] = fmin(dp[j][i], u = (dp[j][i] == 0 ? 0 : u + 1));
            dp[k][i] = fmin(dp[k][i], d = (dp[k][i] == 0 ? 0 : d + 1));
        }
    }
    int res = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            res = fmax(res, dp[i][j]);
    return res;
}
