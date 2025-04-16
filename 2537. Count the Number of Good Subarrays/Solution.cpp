#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    long long countGood(vector<int>& nums, int k)
    {
        unordered_map<int, int> cnt;
        int i = 0, n = nums.size();
        long long good_cnt = 0, ans = 0;
        for (int j = 0; j < n; ++j) {
            good_cnt += cnt[nums[j]]++;
            while (good_cnt >= k) {
                good_cnt -= --cnt[nums[i++]];
                ans += n - j;
            }
        }
        return ans;
    }
};
