#include <stdbool.h>

bool kLengthApart(int *nums, int numsSize, int k)
{
    int gap = k;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i]) {
            if (gap < k)
                return false;
            gap = 0;
        }
        else
            gap++;
    }
    return true;
}
