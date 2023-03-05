#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    int countTriplets(vector<int>& nums)
    {
        int res = 0;
        unordered_map<int, int> cnt;
        for (const int& x : nums)
            for (const int& y : nums)
                cnt[x & y]++;

        for (int x : nums) {
            x ^= 0xffff;
            for (int i = x; i; i = (i - 1) & x)
                res += cnt[i];
            res += cnt[0];
        }
        return res;
    }
};
