#include <vector>
using namespace std;

class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums)
    {
        int ans = 1, i = 0, n = nums.size();
        while (i < n - 1) {
            if (nums[i] == nums[i + 1]) {
                ++i;
                continue;
            }
            int j = i + 1;
            bool inc = nums[j] > nums[i];
            while (j < n && nums[j] != nums[j - 1] && (nums[j] > nums[j - 1]) == inc)
                ++j;
            ans = max(ans, j - i);
            i = j - 1;
        }
        return ans;
    }
};
