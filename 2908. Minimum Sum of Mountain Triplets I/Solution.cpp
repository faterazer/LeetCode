#include <vector>
using namespace std;

class Solution {
public:
    int minimumSum(vector<int>& nums)
    {
        vector<int> suf(nums.size());
        suf.back() = nums.back();
        for (int i = nums.size() - 2; i > 1; i--)
            suf[i] = min(suf[i + 1], nums[i]);

        int res = INT_MAX, pre = nums[0];
        for (size_t i = 1; i < nums.size() - 1; i++) {
            if (pre < nums[i] && nums[i] > suf[i + 1])
                res = min(res, pre + nums[i] + suf[i + 1]);
            pre = min(pre, nums[i]);
        }
        return res == INT_MAX ? -1 : res;
    }
};
