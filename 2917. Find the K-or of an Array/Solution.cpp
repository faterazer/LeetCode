#include <vector>
using namespace std;

class Solution {
public:
    int findKOr(vector<int>& nums, int k)
    {
        int res = 0;
        for (int i = 0; i < 31; i++) {
            int cnt = 0;
            for (int x : nums)
                cnt += x >> i & 1;
            if (cnt >= k)
                res |= 1 << i;
        }
        return res;
    }
};
