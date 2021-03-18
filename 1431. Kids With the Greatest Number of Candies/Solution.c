#include <math.h>
#include <stdbool.h>
#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
bool* kidsWithCandies(int *candies, int candiesSize, int extraCandies, int *returnSize)
{
    bool *res = (bool*)malloc(sizeof(bool) * candiesSize);
    *returnSize = candiesSize;

    int mx = 0;
    for (int i = 0; i < candiesSize; i++)
        mx = fmax(mx, candies[i]);
    for (int i = 0; i < candiesSize; i++)
        res[i] = (candies[i] + extraCandies) >= mx;
    return res;
}
