#define BUFFER_SIZE 100001

#include <stdbool.h>

static int next_dec[BUFFER_SIZE];

bool solve(int* nums, int numsSize, int k)
{
    int last_max = 0;
    for (int r = k - 1; r < numsSize; r += k) {
        int l = r - k + 1;
        int m = next_dec[l];
        if (m >= r) {
            if (last_max > nums[l])
                return false;
            last_max = nums[r];
        } else {
            if (last_max > nums[m + 1] || next_dec[m + 1] < r || nums[r] > nums[l])
                return false;
            last_max = nums[m];
        }
    }
    return true;
}

int sortableIntegers(int* nums, int numsSize)
{
    int p = numsSize;
    next_dec[numsSize - 1] = p;
    for (int i = numsSize - 2; i >= 0; --i) {
        if (nums[i] > nums[i + 1])
            p = i;
        next_dec[i] = p;
    }

    int result = 0;
    for (int k = 1; k * k <= numsSize; ++k) {
        if (numsSize % k == 0) {
            if (solve(nums, numsSize, k))
                result += k;
            if (k * k < numsSize && solve(nums, numsSize, numsSize / k))
                result += numsSize / k;
        }
    }
    return result;
}
