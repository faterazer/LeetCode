#include <math.h>
#include <memory.h>

int specialArray(int *nums, int numsSize)
{
    int counter[numsSize + 1], cnt = 0;
    memset(counter, 0, sizeof(counter));
    for (int i = 0; i < numsSize; i++)
        counter[(int)fmin(nums[i], numsSize)]++;
    for (int i = numsSize; i > 0; i--) {
        cnt += counter[i];
        if (cnt == i)
            return i;
    }
    return -1;
}
