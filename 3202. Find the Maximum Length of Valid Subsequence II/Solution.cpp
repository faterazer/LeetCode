#include <vector>
using namespace std;

class Solution {
public:
    int maximumLength(vector<int>& nums, int k)
    {
        int ans = 0;
        for (int i = 0; i < k; ++i) {
            vector<int> f(k, 0);
            for (int x : nums) {
                x %= k;
                f[x] = f[(i - x + k) % k] + 1;
                ans = max(ans, f[x]);
            }
        }
        return ans;
    }
};
