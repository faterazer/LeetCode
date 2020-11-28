#include <memory.h>
#include <stdlib.h>

int rotatedDigits(int N)
{
    // dp[i] = 0, invalid number
    // dp[i] = 1, valid and same number
    // dp[i] = 2, valid and different number

    int *dp = (int*)malloc(sizeof(int) * (N + 1));
    memset(dp, 0, sizeof(int) * (N + 1));
    int cnt = 0;
    for (int i = 0; i <= N; i++) {
        if (i == 0 || i == 1 || i == 8)
            dp[i] = 1;
        else if (i == 2 || i == 5 || i == 6 || i == 9) {
            dp[i] = 2;
            cnt++;
        }
        else {
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
