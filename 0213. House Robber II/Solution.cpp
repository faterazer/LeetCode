#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums)
    {
        if (nums.size() == 1)
            return nums[0];
        return max(robRange(nums, 0, nums.size() - 1), robRange(nums, 1, nums.size()));
    }

private:
    int robRange(const vector<int>& nums, int beg, int end)
    {
        int pre1 = 0, pre2 = 0, tmp;
        for (int i = beg; i < end; i++) {
            tmp = max(pre1 + nums[i], pre2);
            pre1 = pre2;
            pre2 = tmp;
        }
        return pre2;
    }
};
