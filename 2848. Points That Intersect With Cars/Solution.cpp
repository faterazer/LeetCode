#include <algorithm>
#include <ranges>
#include <vector>
using namespace std;

class Solution {
public:
    int numberOfPoints(vector<vector<int>>& nums)
    {
        int max_end = ranges::max(nums, {}, [](const vector<int>& x) { return x[1]; })[1];
        vector<int> diff(max_end + 2, 0);
        for (const vector<int>& p : nums) {
            ++diff[p[0]];
            --diff[p[1] + 1];
        }
        int res = 0, s = 0;
        for (int d : diff) {
            s += d;
            res += s > 0;
        }
        return res;
    }
};
