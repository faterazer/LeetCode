#include <limits.h>
#include <math.h>

int minOperations(int* nums, int numsSize, int x)
{
    int sum = 0;
    for (int i = 0; i < numsSize; i++)
        sum += nums[i];

    int left = 0, right = 0, window_sum = 0, res = INT_MAX;
    for (; right < numsSize; right++) {
        window_sum += nums[right];
        while (left <= right && sum - window_sum < x)
            window_sum -= nums[left++];
        if (sum - window_sum == x)
            res = fmin(res, numsSize - right + left - 1);
    }
    return res == INT_MAX ? -1 : res;
}
