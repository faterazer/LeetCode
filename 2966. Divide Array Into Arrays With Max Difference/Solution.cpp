#include <algorithm>
#include <ranges>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k)
    {
        ranges::sort(nums);
        vector<vector<int>> ans;
        for (size_t i = 0; i < nums.size(); i += 3) {
            if (nums[i + 2] - nums[i] > k)
                return {};
            ans.push_back({nums[i], nums[i + 1], nums[i + 2]});
        }
        return ans;
    }
};
