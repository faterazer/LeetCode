#include <stdbool.h>

bool check(int *nums, int numsSize)
{
    int cnt = 0;
    for (int i = 0; i < numsSize; i++)
        if (nums[i] > nums[(i + 1) % numsSize] && ++cnt > 1)
            return false;
    return true;
}
