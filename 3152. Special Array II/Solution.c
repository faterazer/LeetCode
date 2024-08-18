#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
bool *isArraySpecial(int *nums, int numsSize, int **queries, int queriesSize, int *queriesColSize, int *returnSize)
{
    int last_same[numsSize];
    memset(last_same, 0, sizeof(last_same));
    for (int i = 1; i < numsSize; i++)
        last_same[i] = (nums[i] & 1) != (nums[i - 1] & 1) ? last_same[i - 1] : i;

    bool *res = (bool *)malloc(sizeof(bool) * queriesSize);
    *returnSize = queriesSize;
    for (int i = 0; i < queriesSize; i++)
        res[i] = last_same[queries[i][1]] <= queries[i][0];
    return res;
}
