#include <ranges>
#include <vector>
using namespace std;

class Solution {
public:
    int findValueOfPartition(vector<int>& nums)
    {
        ranges::sort(nums);
        int res = INT_MAX;
        for (size_t i = 1; i < nums.size(); i++)
            res = min(res, nums[i] - nums[i - 1]);
        return res;
    }
};
