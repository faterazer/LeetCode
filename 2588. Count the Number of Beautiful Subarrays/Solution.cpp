#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    long long beautifulSubarrays(vector<int>& nums)
    {
        unordered_map<int, int> prefix_xor_cnt { { 0, 1 } };
        int prefix_xor = 0;
        long long ans = 0;
        for (int x : nums) {
            prefix_xor ^= x;
            ans += prefix_xor_cnt[prefix_xor]++;
        }
        return ans;
    }
};
