#include <math.h>

int minimumSize(int* nums, int numsSize, int maxOperations)
{
    int left = 1, right = 1;
    for (int i = 0; i < numsSize; i++)
        right = fmax(right, nums[i]);

    while (left < right) {
        int mid = left + ((right - left) >> 1), cnt = 0;
        for (int i = 0; i < numsSize; i++)
            cnt += (nums[i] - 1) / mid;

        if (cnt > maxOperations)
            left = mid + 1;
        else
            right = mid;
    }
    return left;
}
