#include <stdbool.h>

bool search(int* nums, int numsSize, int target)
{
    int l = 0, r = numsSize - 1, m;
    while (l <= r) {
        m = l + ((r - l) >> 1);
        if (nums[m] == target)
            return true;
        if (nums[l] == nums[m] && nums[m] == nums[r]) {
            ++l;
            --r;
        } else if (nums[l] <= nums[m]) {
            if (nums[l] <= target && target < nums[m])
                r = m - 1;
            else
                l = m + 1;
        } else {
            if (nums[m] < target && target <= nums[r])
                l = m + 1;
            else
                r = m - 1;
        }
    }
    return false;
}
