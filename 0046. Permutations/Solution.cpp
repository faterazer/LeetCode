#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums)
    {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        do {
            res.emplace_back(nums);
        } while (next_permute(nums));
        return res;
    }

private:
    bool next_permute(vector<int>& nums)
    {
        int r = nums.size() - 1;
        while (r > 0 && nums[r] < nums[r - 1])
            --r;
        if (r == 0)
            return false;
        sort(nums.begin() + r, nums.end());
        int upper_idx = upper_bound(nums.begin() + r, nums.end(), nums[r - 1]) - nums.begin();
        swap(nums[r - 1], nums[upper_idx]);
        return true;
    }
};
