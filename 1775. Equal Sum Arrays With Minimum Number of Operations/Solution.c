#include <math.h>
#include <stdlib.h>

int helper(int cnt1[], int cnt2[], int diff)
{
    int res = 0;
    for (int i = 1; i <= 6; i++) {
        while (cnt1[i]-- > 0) {
            res++;
            diff -= 6 - i;
            if (diff <= 0)
                return res;
        }
        while (cnt2[7 - i]-- > 0) {
            res++;
            diff -= 6 - i;
            if (diff <= 0)
                return res;
        }
    }
    return res;
}

int minOperations(int* nums1, int nums1Size, int* nums2, int nums2Size)
{
    if (fmax(nums1Size, nums2Size) > 6 * fmin(nums1Size, nums2Size))
        return -1;
    
    int sum1 = 0, sum2 = 0;
    int cnt1[7] = {0}, cnt2[7] = {0};
    for (int i = 0; i < nums1Size; i++) {
        ++cnt1[nums1[i]];
        sum1 += nums1[i];
    }
    for (int i = 0; i < nums2Size; i++) {
        ++cnt2[nums2[i]];
        sum2 += nums2[i];
    }
    
    if (sum1 == sum2)
        return 0;

    int diff = abs(sum1 - sum2);
    if (sum1 < sum2)
        return helper(cnt1, cnt2, diff);
    else
        return helper(cnt2, cnt1, diff);
}
