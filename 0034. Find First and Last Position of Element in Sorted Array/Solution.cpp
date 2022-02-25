#include <vector>
using namespace std;

class Solution {
public:
    vector<int> searchRange_MK1(vector<int>& nums, int target)
    {
        auto it = lower_bound(nums.begin(), nums.end(), target);
        if (it == nums.end() || *it != target)
            return { -1, -1 };
        return { static_cast<int>(it - nums.begin()), static_cast<int>(upper_bound(nums.begin(), nums.end(), target) - 1 - nums.begin()) };
    }

    vector<int> searchRange_MK2(vector<int>& nums, int target)
    {
        vector<int> res(2, -1);
        if (nums.empty())
            return res;
        int l = 0, r = nums.size() - 1, m;
        while (l <= r) {
            m = l + ((r - l) >> 1);
            if (nums[m] >= target)
                r = m - 1;
            else
                l = m + 1;
        }
        if (l >= nums.size() || nums[l] != target)
            return res;
        else
            res[0] = l;
        r = nums.size() - 1;
        while (l <= r) {
            m = l + ((r - l) >> 1);
            if (nums[m] <= target)
                l = m + 1;
            else
                r = m - 1;
        }
        res[1] = l - 1;
        return res;
    }
};
