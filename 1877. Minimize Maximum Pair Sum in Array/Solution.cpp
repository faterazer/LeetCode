#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    int minPairSum(vector<int>& nums)
    {
        sort(nums.begin(), nums.end());
        int res = 0, n = nums.size();
        for (int i = 0, j = n - 1; i < j; ++i, --j)
            res = max(res, nums[i] + nums[j]);
        return res;
    }
};
