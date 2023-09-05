#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    int minNumber(vector<int>& nums1, vector<int>& nums2)
    {
        for (int i = 1; i < 10; i++)
            if (find(nums1.begin(), nums1.end(), i) != nums1.end() && find(nums2.begin(), nums2.end(), i) != nums2.end())
                return i;
        int x = *min_element(nums1.begin(), nums1.end());
        int y = *min_element(nums2.begin(), nums2.end());
        return min(x * 10 + y, y * 10 + x);
    }
};
