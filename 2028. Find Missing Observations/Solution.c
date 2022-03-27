#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* missingRolls(int* rolls, int rollsSize, int mean, int n, int* returnSize)
{
    int missing_sum = mean * (rollsSize + n);
    for (int i = 0; i < rollsSize; ++i)
        missing_sum -= rolls[i];
    if (missing_sum < n || missing_sum > 6 * n) {
        *returnSize = 0;
        return NULL;
    }
    int div = missing_sum / n, mod = missing_sum % n;
    int* res = (int*)malloc(sizeof(int) * n);
    *returnSize = n;
    for (int i = 0; i < n; ++i)
        res[i] = i < mod ? div + 1 : div;
    return res;
}
