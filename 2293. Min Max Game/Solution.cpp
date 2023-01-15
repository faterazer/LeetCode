#include <vector>
using namespace std;

class Solution {
public:
    int minMaxGame(vector<int>& nums)
    {
        for (int n = nums.size(); n != 1; n >>= 1) {
            for (int i = 0; i < n / 2; i++) {
                if (i & 1)
                    nums[i] = max(nums[i << 1], nums[i << 1 | 1]);
                else
                    nums[i] = min(nums[i << 1], nums[i << 1 | 1]);
            }
        }
        return nums[0];
    }
};
