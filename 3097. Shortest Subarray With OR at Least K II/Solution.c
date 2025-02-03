#include <limits.h>
#include <math.h>

int minimumSubarrayLength(int* nums, int numsSize, int k)
{
    long long ans = INT_MAX;
    int left = 0, bottom = 0, right_or = 0;
    for (int right = 0; right < numsSize; ++right) {
        right_or |= nums[right];
        while (left <= right && (nums[left] | right_or) >= k) {
            ans = fmin(ans, right - left + 1);
            ++left;
            if (bottom < left) {
                for (int i = right - 1; i >= left; --i)
                    nums[i] |= nums[i + 1];
                bottom = right;
                right_or = 0;
            }
        }
    }
    return ans == INT_MAX ? -1 : ans;
}
