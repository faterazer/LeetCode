#include <vector>
using namespace std;

class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k)
    {
        int ans = INT_MAX, i = 0, bottom = 0, right_or = 0;
        for (int j = 0; j < nums.size(); ++j) {
            right_or |= nums[j];
            while (i <= j && (nums[i] | right_or) >= k) {
                ans = min(ans, j - i + 1);
                ++i;
                if (bottom < i) {
                    for (int k = j - 1; k >= i; --k)
                        nums[k] |= nums[k + 1];
                    bottom = j;
                    right_or = 0;
                }
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};
