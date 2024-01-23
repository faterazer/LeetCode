#include <vector>
using namespace std;

class Solution {
public:
    int alternatingSubarray(vector<int>& nums)
    {
        int res = -1, dp = -1;
        for (size_t i = 1; i < nums.size(); i++) {
            if (dp >= 2 && nums[i] == nums[i - 2])
                ++dp;
            else
                dp = nums[i] == nums[i - 1] + 1 ? 2 : -1;
            res = max(res, dp);
        }
        return res;
    }
};
