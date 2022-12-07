#include <numeric>
#include <vector>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums1, vector<int>& nums2)
    {
        int m = nums1.size(), n = nums2.size();
        if (max(m, n) > 6 * min(m, n))
            return -1;
        int sum1 = accumulate(nums1.begin(), nums1.end(), 0), sum2 = accumulate(nums2.begin(), nums2.end(), 0);
        if (sum1 == sum2)
            return 0;
        if (sum1 > sum2) {
            swap(sum1, sum2);
            swap(nums1, nums2);
        }

        vector<int> cnt1(7, 0), cnt2(7, 0);
        for (const int& x : nums1)
            ++cnt1[x];
        for (const int& x : nums2)
            ++cnt2[x];

        int res = 0;
        for (int i = 1; i <= 6; i++) {
            while (cnt1[i]-- > 0) {
                res++;
                sum1 += 6 - i;
                if (sum1 >= sum2)
                    return res;
            }
            while (cnt2[7 - i]-- > 0) {
                res++;
                sum2 -= 6 - i;
                if (sum1 >= sum2)
                    return res;
            }
        }
        return res;
    }
};
