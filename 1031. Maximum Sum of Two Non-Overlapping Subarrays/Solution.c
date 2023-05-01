#include <math.h>

int helper(int* nums, int numsSize, int firstLen, int secondLen)
{
    int first_sum = 0, second_sum = 0;
    for (int i = 0; i < firstLen; i++)
        first_sum += nums[i];
    for (int i = firstLen; i < firstLen + secondLen; i++)
        second_sum += nums[i];
    int max_first_sum = first_sum, res = max_first_sum + second_sum;
    for (int i = firstLen; i + secondLen < numsSize; i++) {
        first_sum += nums[i] - nums[i - firstLen];
        max_first_sum = fmax(max_first_sum, first_sum);
        second_sum += nums[i + secondLen] - nums[i];
        res = fmax(res, max_first_sum + second_sum);
    }
    return res;
}

int maxSumTwoNoOverlap(int* nums, int numsSize, int firstLen, int secondLen)
{
    return fmax(helper(nums, numsSize, firstLen, secondLen), helper(nums, numsSize, secondLen, firstLen));
}
