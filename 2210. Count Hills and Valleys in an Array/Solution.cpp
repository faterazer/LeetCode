#include <vector>
using namespace std;

class Solution {
public:
    int countHillValley(vector<int>& nums)
    {
        size_t i = 0, j = 1;
        while (j < nums.size() && nums[j] == nums[i])
            ++j;
        int ans = 0;
        for (size_t k = j + 1; k < nums.size(); ++k) {
            if (nums[k] == nums[j])
                continue;
            if (nums[j] < min(nums[i], nums[k]) || nums[j] > max(nums[i], nums[k]))
                ++ans;
            i = j;
            j = k;
        }
        return ans;
    }
};
