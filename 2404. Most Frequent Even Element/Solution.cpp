#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    int mostFrequentEven(vector<int>& nums)
    {
        unordered_map<int, int> cnt;
        int res = -1;
        for (const int& x : nums) {
            if (x & 1)
                continue;
            int c = ++cnt[x];
            if (c > cnt[res] || (c == cnt[res] && x < res))
                res = x;
        }
        return res;
    }
};
