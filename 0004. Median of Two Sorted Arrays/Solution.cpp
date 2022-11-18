#include <climits>
#include <vector>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
    {
        if (nums1.size() > nums2.size())
            return findMedianSortedArrays(nums2, nums1);

        int m = nums1.size(), n = nums2.size();
        int lo = 0, hi = m;
        int median1 = 0, median2 = 0;
        while (lo <= hi) {
            int i = lo + ((hi - lo) >> 1);
            int j = (m + n + 1) / 2 - i;

            int nums1_i1 = (i == 0 ? INT_MIN : nums1[i - 1]);
            int nums1_i2 = (i == m ? INT_MAX : nums1[i]);
            int nums2_j1 = (j == 0 ? INT_MIN : nums2[j - 1]);
            int nums2_j2 = (j == n ? INT_MAX : nums2[j]);

            if (nums1_i1 <= nums2_j2) {
                median1 = max(nums1_i1, nums2_j1);
                median2 = min(nums1_i2, nums2_j2);
                lo = i + 1;
            } else
                hi = i - 1;
        }
        return (m + n) % 2 == 0 ? (median1 + median2) / 2.0 : median1;
    }
};
