#include <algorithm>
#include <ranges>
#include <vector>
using namespace std;

class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper)
    {
        ranges::sort(nums);
        long long ans = 0;
        for (size_t i = 0; i < nums.size() - 1; ++i) {
            int a = lower_bound(nums.begin() + i + 1, nums.end(), lower - nums[i]) - nums.begin();
            int b = upper_bound(nums.begin() + i + 1, nums.end(), upper - nums[i]) - nums.begin();
            if (a < b)
                ans += b - a;
        }
        return ans;
    }
};
