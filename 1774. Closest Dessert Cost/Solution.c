#include <limits.h>
#include <math.h>
#include <string.h>

int closestCost(int* baseCosts, int baseCostsSize, int* toppingCosts, int toppingCostsSize, int target)
{
    int min_base_cost = INT_MAX;
    for (int i = 0; i < baseCostsSize; i++)
        min_base_cost = fmin(min_base_cost, baseCosts[i]);
    if (min_base_cost >= target)
        return min_base_cost;

    int res = target - min_base_cost;
    int dp[target + 1];
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < baseCostsSize; i++) {
        if (baseCosts[i] < target)
            dp[baseCosts[i]] = 1;
        else
            res = fmin(res, baseCosts[i] - target);
    }

    for (int i = 0; i < toppingCostsSize; i++) {
        for (int count = 0; count < 2; count++) {
            for (int j = target; j; j--) {
                if (dp[j]) {
                    if (j + toppingCosts[i] <= target)
                        dp[j + toppingCosts[i]] = 1;
                    else
                        res = fmin(res, j + toppingCosts[i] - target);
                }
            }
        }
    }

    for (int i = target; i >= target - res; i--)
        if (dp[i])
            return i;
    return target + res;
}
