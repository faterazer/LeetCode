#include <stdlib.h>
#include <string.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* smallestSubarrays_MK1(int* nums, int numsSize, int* returnSize) // LogTrick
{
    *returnSize = numsSize;
    int* ans = (int*)malloc(sizeof(int) * numsSize);
    for (int i = 0; i < numsSize; ++i) {
        ans[i] = 1;
        for (int j = i - 1; j >= 0 && (nums[j] | nums[i]) != nums[j]; --j) {
            nums[j] |= nums[i];
            ans[j] = i - j + 1;
        }
    }
    return ans;
}

int* smallestSubarrays_MK2(int* nums, int numsSize, int* returnSize) // 滑动窗口 + 栈
{
    *returnSize = numsSize;
    int* ans = (int*)malloc(sizeof(int) * numsSize);
    ans[numsSize - 1] = 1;
    if (numsSize == 1)
        return ans;
    nums[numsSize - 1] |= nums[numsSize - 2];
    int left_or = 0, bottom = numsSize - 2, right = numsSize - 1;
    for (int left = numsSize - 2; left >= 0; --left) {
        left_or |= nums[left];
        while (right > left && (left_or | nums[right]) == (left_or | nums[right - 1])) {
            --right;
            if (bottom >= right) {
                for (int i = left + 1; i <= right; ++i)
                    nums[i] |= nums[i - 1];
                bottom = left;
                left_or = 0;
            }
        }
        ans[left] = right - left + 1;
    }
    return ans;
}
