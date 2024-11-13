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
        int left = nums.size(), right = nums.size(), n = nums.size();
        for (int j = 0; j < n; ++j) {
            while (left && nums[left - 1] >= lower - nums[j])
                --left;
            while (right && nums[right - 1] > upper - nums[j])
                --right;
            ans += min(right, j) - min(left, j);
        }
        return ans;
    }
};
