#include <memory.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * Time complexity: O(n)
 * Space complexity: O(n)
 */
int rotatedDigits_MK1(int N)
{
    // dp[i] = 0, invalid number
    // dp[i] = 1, valid and same number
    // dp[i] = 2, valid and different number

    int* dp = (int*)malloc(sizeof(int) * (N + 1));
    memset(dp, 0, sizeof(int) * (N + 1));
    int cnt = 0;
    for (int i = 0; i <= N; i++) {
        if (i == 0 || i == 1 || i == 8)
            dp[i] = 1;
        else if (i == 2 || i == 5 || i == 6 || i == 9) {
            dp[i] = 2;
            cnt++;
        } else {
            int a = dp[i % 10], b = dp[i / 10];
            if (a == 1 && b == 1)
                dp[i] = 1;
            else if (a >= 1 && b >= 1) {
                dp[i] = 2;
                cnt++;
            }
        }
    }
    free(dp);
    return cnt;
}

int check[10] = { 0, 0, 1, -1, -1, 1, 1, -1, 0, 1 };

int dfs(char* s, int pos, bool is_limit, bool has_diff, int memo[][2])
{
    if (!s[pos])
        return has_diff;
    if (!is_limit && memo[pos][has_diff] > -1)
        return memo[pos][has_diff];

    int lim = is_limit ? s[pos] - '0' : 9;
    int res = 0;
    for (int i = 0; i <= lim; i++) {
        if (check[i] != -1)
            res += dfs(s, pos + 1, is_limit && i == lim, has_diff || check[i] == 1, memo);
    }
    if (!is_limit)
        memo[pos][has_diff] = res;
    return res;
}

/**
 * Time complexity: O(lgn)
 * Space complexity: O(lgn)
 */
int rotatedDigits_MK2(int n)
{
    char s[20] = { '\0' };
    sprintf(s, "%d", n);

    int dp[n][2];
    memset(dp, -1, sizeof(dp));

    return dfs(s, 0, true, false, dp);
}
