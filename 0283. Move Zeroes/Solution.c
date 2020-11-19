#include <memory.h>

void moveZeroes(int *nums, int numsSize)
{
    int last = 0;
    for (int i = 0; i < numsSize; i++)
        if (nums[i])
            nums[last++] = nums[i];
    memset(nums + last, 0, (numsSize - last) * sizeof(int));
}
