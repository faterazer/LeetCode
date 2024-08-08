#include <ranges>
#include <vector>
using namespace std;

class Solution {
public:
    int addedInteger(vector<int>& nums1, vector<int>& nums2)
    {
        return *ranges::min_element(nums2) - *ranges::min_element(nums1);
    }
};
