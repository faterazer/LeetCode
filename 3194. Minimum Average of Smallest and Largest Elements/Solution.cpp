#include <algorithm>
#include <ranges>
#include <vector>
using namespace std;

class Solution {
public:
    double minimumAverage(vector<int>& nums)
    {
        ranges::sort(nums);
        int ans = INT_MAX;
        for (int i = 0, j = nums.size() - 1; i < j; ++i, --j)
            ans = min(ans, nums[i] + nums[j]);
        return ans / 2.0;
    }
};
