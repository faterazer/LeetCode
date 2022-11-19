#include <limits.h>
#include <math.h>

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size)
{
    if (nums1Size > nums2Size)
        return findMedianSortedArrays(nums2, nums2Size, nums1, nums1Size);

    int lo = 0, hi = nums1Size;
    int median1 = 0, median2 = 0;
    while (lo <= hi) {
        int i = lo + ((hi - lo) >> 1);
        int j = (nums1Size + nums2Size + 1) / 2 - i;

        int nums1_i1 = (i == 0 ? INT_MIN : nums1[i - 1]);
        int nums1_i2 = (i == nums1Size ? INT_MAX : nums1[i]);
        int nums2_j1 = (j == 0 ? INT_MIN : nums2[j - 1]);
        int nums2_j2 = (j == nums2Size ? INT_MAX : nums2[j]);

        if (nums1_i1 <= nums2_j2) {
            median1 = fmax(nums1_i1, nums2_j1);
            median2 = fmin(nums1_i2, nums2_j2);
            lo = i + 1;
        } else
            hi = i - 1;
    }
    return ((nums1Size + nums2Size) & 1) ? median1 : (median1 + median2) / 2.0;
}
