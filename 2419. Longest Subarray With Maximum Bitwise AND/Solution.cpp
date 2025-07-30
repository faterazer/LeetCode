#include <vector>
using namespace std;

class Solution {
public:
    int longestSubarray(vector<int>& nums)
    {
        int ans = 0, mx = 0, cnt = 0;
        for (int x : nums) {
            if (x > mx) {
                ans = cnt = 1;
                mx = x;
            } else if (x == mx)
                ans = max(ans, ++cnt);
            else
                cnt = 0;
        }
        return ans;
    }
};
