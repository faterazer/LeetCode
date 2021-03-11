#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* createTargetArray(int *nums, int numsSize, int *index, int indexSize, int *returnSize)
{
    int *res = (int*)malloc(sizeof(int) * numsSize);
    *returnSize = 0;
    for (int i = 0; i < numsSize; i++) {
        if (index[i] < *returnSize) {
            for (int j = *returnSize; j > index[i]; j--)
                res[j] = res[j - 1];
        }
        res[index[i]] = nums[i];
        (*returnSize)++;
    }
    return res;
}
