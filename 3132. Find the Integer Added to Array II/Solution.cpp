#include <ranges>
#include <vector>
using namespace std;

class Solution {
public:
    int minimumAddedInteger(vector<int>& nums1, vector<int>& nums2)
    {
        ranges::sort(nums1);
        ranges::sort(nums2);
        for (int i = 2; i > 0; i--) {
            int d = nums2[0] - nums1[i];
            for (size_t j = i, k = 0; j < nums1.size(); j++)
                if (nums1[j] + d == nums2[k] && ++k == nums2.size())
                    return d;
        }
        return nums2[0] - nums1[0];
    }
};
