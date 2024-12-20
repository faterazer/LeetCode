#include <vector>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums)
    {
        int ans = 0, n = nums.size();
        for (int i = 0; i < n - 2; ++i) {
            if (nums[i] == 0) {
                nums[i + 1] ^= 1;
                nums[i + 2] ^= 1;
                ++ans;
            }
        }
        return nums[n - 2] && nums[n - 1] ? ans : -1;
    }
};
