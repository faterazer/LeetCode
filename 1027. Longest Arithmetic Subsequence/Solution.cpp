#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    int longestArithSeqLength(vector<int>& nums)
    {
        auto [min_it, max_it] = minmax_element(nums.begin(), nums.end());
        int diff = *max_it - *min_it;
        int res = 1;
        for (int d = -diff; d <= diff; d++) {
            vector<int> f(*max_it + 1, 0);
            for (const int& x : nums) {
                if (int prev = x + d; prev >= *min_it && prev <= *max_it) {
                    f[x] = max(f[x], f[prev] + 1);
                    res = max(res, f[x]);
                }
                f[x] = max(f[x], 1);
            }
        }
        return res;
    }
};
