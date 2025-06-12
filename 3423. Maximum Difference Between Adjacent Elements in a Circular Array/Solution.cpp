#include <vector>
using namespace std;

class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums)
    {
        int ans = abs(nums[0] - nums.back());
        for (size_t i = 1; i < nums.size(); ++i)
            ans = max(ans, abs(nums[i] - nums[i - 1]));
        return ans;
    }
};
