#include <vector>
using namespace std;

class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k)
    {
        int n = nums.size(), s = 0;
        vector<int> cnt(min(n + 1, modulo), 0);
        cnt[0] = 1;
        long long ans = 0;
        for (int x : nums) {
            s += x % modulo == k;
            if (s >= k)
                ans += cnt[(s - k) % modulo];
            ++cnt[s % modulo];
        }
        return ans;
    }
};
