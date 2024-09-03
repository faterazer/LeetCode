#include <vector>
using namespace std;

class Solution {
public:
    long long maxStrength(vector<int>& nums)
    {
        long long mn = nums[0], mx = nums[0];
        for (size_t i = 1; i < nums.size(); i++) {
            long long x = nums[i], tmp_mn = mn;
            mn = min({ mn, x, mn * x, mx * x });
            mx = max({ mx, x, tmp_mn * x, mx * x });
        }
        return mx;
    }
};
