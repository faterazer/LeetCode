#include <vector>
using namespace std;

class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2)
    {
        int result = 0, i = 0, j = 0, n1 = nums1.size(), n2 = nums2.size();
        while (i < n1 && j < n2) {
            if (nums1[i] <= nums2[j]) {
                result = max(result, j - i);
                ++j;
            } else
                ++i;
        }
        return result;
    }
};
