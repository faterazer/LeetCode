#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    int countNicePairs(vector<int>& nums)
    {
        int res = 0, MOD = 1e9 + 7;
        unordered_map<int, int> cnt;
        for (const int& x : nums) {
            int rx = x - rev(x);
            res = (res + cnt[rx]) % MOD;
            ++cnt[rx];
        }
        return res;
    }

private:
    int rev(int x)
    {
        int res = 0;
        while (x) {
            res = res * 10 + x % 10;
            x /= 10;
        }
        return res;
    }
};
