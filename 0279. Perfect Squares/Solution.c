#include <limits.h>
#include <math.h>
#include <stdbool.h>

int numSquares_MK1(int n)
{
    /**
     * Time complexity: O(n√n)
     * Space complexity: O(n)
     */

    int dp[n + 1];
    dp[0] = 0;
    for (int i = 1; i <= n; i++) {
        dp[i] = INT_MAX;
        for (int j = 1; j * j <= i; j++)
            dp[i] = fmin(dp[i], 1 + dp[i - j * j]);
    }
    return dp[n];
}

bool isPerfectSquare(int x)
{
    int y = sqrt(x);
    return y * y == x;
}

bool check(int x)
{
    while (x % 4 == 0)
        x /= 4;
    return x % 8 == 7;
}

int numSquares_MK2(int n)
{
    if (isPerfectSquare(n))
        return 1;
    if (check(n))
        return 4;
    for (int i = 1; i * i <= n; i++)
        if (isPerfectSquare(n - i * i))
            return 2;
    return 3;
}
