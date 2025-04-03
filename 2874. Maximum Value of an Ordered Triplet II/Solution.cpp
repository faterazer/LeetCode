#include <vector>
using namespace std;

class Solution {
public:
    long long maximumTripletValue(vector<int>& nums)
    {
        long long ans = 0, mx = 0, max_margin = 0;
        for (int x : nums) {
            ans = max(ans, max_margin * x);
            max_margin = max(max_margin, mx - x);
            mx = max(mx, x * 1LL);
        }
        return ans;
    }
};
