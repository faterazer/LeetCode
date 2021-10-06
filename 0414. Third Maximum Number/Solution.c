#include <limits.h>

int thirdMax(int* nums, int numsSize)
{
    long long buff[3] = { LLONG_MIN, LLONG_MIN, LLONG_MIN };
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] == buff[0] || nums[i] == buff[1] || nums[i] == buff[2])
            continue;
        if (nums[i] > buff[2]) {
            buff[0] = buff[1];
            buff[1] = buff[2];
            buff[2] = nums[i];
        } else if (nums[i] > buff[1]) {
            buff[0] = buff[1];
            buff[1] = nums[i];
        } else if (nums[i] > buff[0]) {
            buff[0] = nums[i];
        }
    }
    return buff[0] == LLONG_MIN ? buff[2] : buff[0];
}
