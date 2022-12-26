#include <math.h>
#include <string.h>

int gcd(int a, int b)
{
    if (!b)
        return a;
    return gcd(b, a % b);
}

int bitCount(int x)
{
    int res = 0;
    while (x) {
        ++res;
        x &= x - 1;
    }
    return res;
}

int maxScore(int* nums, int numsSize)
{
    int dp[1 << numsSize];
    memset(dp, 0, sizeof(dp));

    int gcd_tmp[numsSize][numsSize];
    for (int i = 0; i < numsSize; i++)
        for (int j = i + 1; j < numsSize; j++)
            gcd_tmp[i][j] = gcd(nums[i], nums[j]);

    int n = 1 << numsSize;
    for (int s = 3; s < n; s++) {
        int cnt = bitCount(s);
        if (cnt & 1)
            continue;

        for (int i = 0; i < numsSize; i++) {
            if ((s >> i) & 1) {
                for (int j = i + 1; j < numsSize; j++) {
                    if ((s >> j) & 1) {
                        dp[s] = fmax(dp[s], dp[s ^ (1 << i) ^ (1 << j)] + cnt / 2 * gcd_tmp[i][j]);
                    }
                }
            }
        }
    }
    return dp[n - 1];
}
