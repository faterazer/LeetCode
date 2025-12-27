#include <limits.h>
#include <math.h>

long long maximumProfit(int* prices, int pricesSize, int k)
{
    const long long NEG_INF = LLONG_MIN / 2;
    long long dp[k + 2][3];
    for (int i = 0; i < k + 2; ++i) {
        dp[i][0] = 0;
        dp[i][1] = NEG_INF;
        dp[i][2] = NEG_INF;
    }
    for (int i = 0; i < pricesSize; ++i) {
        int price = prices[i];
        for (int j = k + 1; j > 0; --j) {
            dp[j][1] = fmax(dp[j][1], dp[j][0] - price);
            dp[j][2] = fmax(dp[j][2], dp[j][0] + price);
            dp[j][0] = fmax(dp[j][0], fmax(dp[j - 1][1] + price, dp[j - 1][2] - price));
        }
    }
    return dp[k + 1][0];
}
