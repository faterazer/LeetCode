#include <vector>
using namespace std;

class Solution {
public:
    int countSubarrays(vector<int>& nums)
    {
        int ans = 0;
        for (size_t i = 2; i < nums.size(); ++i)
            if (2 * (nums[i - 2] + nums[i]) == nums[i - 1])
                ++ans;
        return ans;
    }
};
