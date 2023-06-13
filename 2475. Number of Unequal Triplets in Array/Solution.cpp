#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    int unequalTriplets(vector<int>& nums)
    {
        unordered_map<int, int> cnt;
        for (int x : nums)
            cnt[x]++;
        int res = 0, n = nums.size(), t = 0;
        for (const auto& [_, v] : cnt) {
            res += t * v * (n - t - v);
            t += v;
        }
        return res;
    }
};
