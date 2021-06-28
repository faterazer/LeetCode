#include <stdbool.h>

bool canBeIncreasing(int *nums, int numsSize)
{
    int cnt = 0;
    for (int i = 1; i < numsSize; i++) {
        if (nums[i] <= nums[i - 1]) {
            if (i - 2 >= 0 && nums[i] <= nums[i - 2])
                nums[i] = nums[i - 1];
            cnt++;
        }
    }
    return cnt < 2;
}
