#include <math.h>

int partitionDisjoint(int* nums, int numsSize)
{
    int res = 1, last_max = nums[0], cur_max = nums[0];
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] < last_max) {
            res = i + 1;
            last_max = cur_max;
        } else
            cur_max = fmax(cur_max, nums[i]);
    }
    return res;
}
