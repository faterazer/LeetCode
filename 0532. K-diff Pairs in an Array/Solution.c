#include <stdlib.h>

int cmp(const void* a, const void* b)
{
    return *(int*)a - *(int*)b;
}

int findPairs(int* nums, int numsSize, int k)
{
    qsort(nums, numsSize, sizeof(int), cmp);
    int slow = 0, fast = 0, res = 0;
    while (fast < numsSize) {
        if (nums[fast] - nums[slow] < k)
            ++fast;
        else if (nums[fast] - nums[slow] > k)
            ++slow;
        else {
            while (fast < numsSize && nums[fast] - nums[slow] == k)
                ++fast;
            res += fast - 1 != slow;
        }
    }
    return res;
}
