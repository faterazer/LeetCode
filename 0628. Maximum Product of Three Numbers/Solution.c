#include <limits.h>
#include <stdlib.h>

/**
 * Time complexity: O(nlgn).
 * Space complexity: O(1);
 */
#define max(a, b) ((a > b) ? (a) : (b))
#define min(a, b) ((a < b) ? (a) : (b))

int cmp(const void *a, const void *b)
{
    return *(const int *)a - *(const int *)b;
}

int maximumProduct_MK1(int *nums, int numsSize)
{
    qsort(nums, numsSize, sizeof(int), cmp);
    return max(nums[0] * nums[1] * nums[numsSize - 1], nums[numsSize - 1] * nums[numsSize - 2] * nums[numsSize - 3]);
}

/**
 * Time complexity: O(n)
 * Space complexity: O(1)
 */
int maximumProduct_MK2(int *nums, int numsSize)
{
    int max1 = INT_MIN, max2 = INT_MIN, max3 = INT_MIN;
    int min1 = INT_MAX, min2 = INT_MAX;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] > max1) {
            max3 = max2;
            max2 = max1;
            max1 = nums[i];
        }
        else if (nums[i] > max2) {
            max3 = max2;
            max2 = nums[i];
        }
        else if (nums[i] > max3)
            max3 = nums[i];
        if (nums[i] < min1) {
            min2 = min1;
            min1 = nums[i];
        }
        else if (nums[i] < min2)
            min2 = nums[i];
    }
    return max(max1 * max2 * max3, max1 * min1 * min2);
}
