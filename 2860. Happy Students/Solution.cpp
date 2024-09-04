#include <ranges>
#include <vector>
using namespace std;

class Solution {
public:
    int countWays(vector<int>& nums)
    {
        ranges::sort(nums);
        int n = nums.size(), res = (0 < nums[0]) + (n > nums.back());
        for (int i = 1; i < n; i++)
            res += (i > nums[i - 1]) && (i < nums[i]);
        return res;
    }
};
