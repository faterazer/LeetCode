class Solution {
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
        if (nums1.length > nums2.length) {
            return findMedianSortedArrays(nums2, nums1);
        }
        int n = nums1.length, m = nums2.length;
        int lo = 0, hi = n;
        int median1 = 0, median2 = 0;
        while (lo <= hi) {
            int i = lo + ((hi - lo) >> 1);
            int j = (m + n + 1) / 2 - i;

            int nums1_i1 = (i == 0 ? Integer.MIN_VALUE : nums1[i - 1]);
            int nums1_i2 = (i == n ? Integer.MAX_VALUE : nums1[i]);
            int nums2_j1 = (j == 0 ? Integer.MIN_VALUE : nums2[j - 1]);
            int nums2_j2 = (j == m ? Integer.MAX_VALUE : nums2[j]);

            if (nums1_i1 <= nums2_j2) {
                median1 = Math.max(nums1_i1, nums2_j1);
                median2 = Math.min(nums1_i2, nums2_j2);
                lo = i + 1;
            } else {
                hi = i - 1;
            }
        }
        return (n + m) % 2 == 0 ? (median1 + median2) / 2.0 : median1;
    }
}
