#include <ranges>
#include <vector>
using namespace std;

class Solution {
public:
    int maximumCount(vector<int>& nums)
    {
        int neg_cnt = ranges::lower_bound(nums, 0) - nums.begin();
        int pos_cnt = nums.end() - ranges::upper_bound(nums, 0);
        return max(pos_cnt, neg_cnt);
    }
};
