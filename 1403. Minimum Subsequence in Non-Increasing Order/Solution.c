#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* minSubsequence(int *nums, int numsSize, int *returnSize)
{
    int hash[101] = {0};
    int sum1 = 0, sum2 = 0;
    for (int i = 0; i < numsSize; i++) {
        hash[nums[i]]++;
        sum2 += nums[i];
    }

    int *res = (int*)malloc(sizeof(int) * (numsSize / 2 + 1));
    *returnSize = 0;
    for (int i = 100; i > 0; i--) {
        while (hash[i]--) {
            res[(*returnSize)++] = i;
            sum1 += i;
            sum2 -= i;
            if (sum1 > sum2) {
                res = (int*)realloc(res, *returnSize * sizeof(int));
                return res;
            }
        }
    }
    free(res);
    return NULL;
}
