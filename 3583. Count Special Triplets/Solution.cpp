#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    int specialTriplets(vector<int>& nums)
    {
        unordered_map<int, int> suf_cnt;
        for (int x : nums)
            ++suf_cnt[x];
        int result = 0;
        unordered_map<int, int> pre_cnt;
        for (int x : nums) {
            --suf_cnt[x];
            result = (result + 1LL * pre_cnt[x * 2] * suf_cnt[x * 2]) % MOD;
            ++pre_cnt[x];
        }
        return result;
    }

private:
    static constexpr int MOD = 1'000'000'007;
};
