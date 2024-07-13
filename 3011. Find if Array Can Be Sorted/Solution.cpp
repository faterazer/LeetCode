#include <bit>
#include <vector>
using namespace std;

class Solution {
public:
    bool canSortArray(vector<int>& nums)
    {
        int last_mx = INT_MIN, mn = nums[0], mx = nums[0];
        for (size_t i = 1; i < nums.size(); i++) {
            if (popcount(static_cast<unsigned>(nums[i])) == popcount(static_cast<unsigned>(nums[i - 1]))) {
                mn = min(mn, nums[i]);
                mx = max(mx, nums[i]);
            } else {
                if (mn < last_mx)
                    return false;
                last_mx = mx;
                mn = mx = nums[i];
            }
        }
        return mn >= last_mx;
    }
};
