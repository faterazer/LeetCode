#include <stdlib.h>

int cmp(const void* a, const void* b)
{
    return *(int*)a - *(int*)b;
}

int triangleNumber_MK1(int* nums, int numsSize)
{
    qsort(nums, numsSize, sizeof(int), cmp);
    int ans = 0;
    for (int k = numsSize - 1; k >= 2; --k) {
        if (nums[0] + nums[1] > nums[k]) {
            ans += (k + 1) * k * (k - 1) / 6;
            break;
        }
        if (nums[k - 1] + nums[k - 2] <= nums[k])
            continue;

        int i = 0, j = k - 1;
        while (i < j) {
            if (nums[i] + nums[j] > nums[k]) {
                ans += j - i;
                --j;
            } else
                ++i;
        }
    }
    return ans;
}

int triangleNumber_MK2(int* nums, int numsSize)
{
    qsort(nums, numsSize, sizeof(int), cmp);
    int ans = 0;
    for (int i = 0; i < numsSize - 2; ++i) {
        if (nums[i] == 0)
            continue;

        int j = i + 1;
        for (int k = i + 1; k < numsSize; ++k) {
            while (nums[i] + nums[j] <= nums[k])
                ++j;
            ans += k - j;
        }
    }
    return ans;
}
