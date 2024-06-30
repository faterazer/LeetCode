#include <numeric>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target)
    {
        int s = reduce(nums.begin(), nums.end(), 0) - abs(target);
        if (s < 0 || s % 2 == 1)
            return 0;
        int m = s / 2;

        vector<int> f(m + 1, 0);
        f[0] = 1;
        for (int x : nums)
            for (int i = m; i >= x; i--)
                f[i] += f[i - x];
        return f[m];
    }
};
