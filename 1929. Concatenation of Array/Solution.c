#include <memory.h>
#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* getConcatenation(int *nums, int numsSize, int *returnSize)
{
    int *res = (int*)malloc(sizeof(int) * numsSize * 2);
    memcpy(res, nums, sizeof(int) * numsSize);
    memcpy(res + numsSize, nums, sizeof(int) * numsSize);
    *returnSize = 2 * numsSize;
    return res;
}
