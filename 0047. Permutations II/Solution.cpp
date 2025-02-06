#include <algorithm>
#include <ranges>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums)
    {
        vector<vector<int>> ans;
        ranges::sort(nums);
        do {
            ans.emplace_back(nums);
        } while (next_permutation(nums));
        return ans;
    }

private:
    bool next_permutation(vector<int>& nums)
    {
        int r = nums.size() - 1;
        while (r > 0 && nums[r - 1] >= nums[r])
            r--;
        if (r == 0)
            return false;
        sort(nums.begin() + r, nums.end());
        int upper_idx = upper_bound(nums.begin() + r, nums.end(), nums[r - 1]) - nums.begin();
        swap(nums[r - 1], nums[upper_idx]);
        return true;
    }
};
