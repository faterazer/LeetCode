#include <vector>
using namespace std;

class Solution {
public:
    long long maximumOr(vector<int>& nums, int k)
    {
        int all_or = 0, fixed = 0;
        for (int x : nums) {
            fixed |= all_or & x;
            all_or |= x;
        }

        long long ans = 0;
        for (int x : nums) {
            long long xll = x;
            ans = max(ans, (all_or ^ x) | fixed | (xll << k));
        }
        return ans;
    }
};
