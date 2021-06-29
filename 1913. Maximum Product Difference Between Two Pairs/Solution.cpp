#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
    int maxProductDifference(vector<int> &nums)
    {
        nth_element(nums.begin(), nums.begin() + 2, nums.end());
        nth_element(nums.begin() + 2, nums.begin() + nums.size() - 2, nums.end());
        return nums.back() * nums[nums.size() - 2] - nums[0] * nums[1];
    }
};
