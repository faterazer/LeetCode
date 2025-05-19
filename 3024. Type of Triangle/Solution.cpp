#include <algorithm>
#include <ranges>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string triangleType(vector<int>& nums)
    {
        ranges::sort(nums);
        if (nums[0] + nums[1] <= nums[2])
            return "none";
        else if (nums[0] == nums[1] && nums[0] == nums[2])
            return "equilateral";
        else if (nums[0] == nums[1] || nums[1] == nums[2])
            return "isosceles";
        else
            return "scalene";
    }
};
