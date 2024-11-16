#include <stdlib.h>
#include <string.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* resultsArray(int* nums, int numsSize, int k, int* returnSize)
{
    *returnSize = numsSize - k + 1;
    int* ans = (int*)malloc(sizeof(int) * (*returnSize));
    memset(ans, -1, sizeof(int) * (*returnSize));

    int window_size = 0;
    for (int i = 0; i < numsSize; ++i) {
        if (i == 0 || nums[i] == nums[i - 1] + 1)
            ++window_size;
        else
            window_size = 1;

        if (window_size >= k)
            ans[i - k + 1] = nums[i];
    }
    return ans;
}
