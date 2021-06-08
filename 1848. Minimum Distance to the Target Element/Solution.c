#include <math.h>
#include <limits.h>

int getMinDistance(int *nums, int numsSize, int target, int start)
{
    int res = INT_MAX;
    for (int i = 0; i < numsSize && res >= abs(i - start); i++)
        if (nums[i] == target)
            res = abs(i - start);
    return res;
}
