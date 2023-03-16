#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    int countSubarrays(vector<int>& nums, int k)
    {
        unordered_map<int, int> cnt { { 0, 1 } };
        int pos = find(nums.begin(), nums.end(), k) - nums.begin(), n = nums.size();
        for (int i = pos - 1, bal = 0; i >= 0; i--) {
            bal += nums[i] > k ? -1 : 1;
            ++cnt[bal];
        }
        int res = cnt[0] + cnt[-1];
        for (int i = pos + 1, bal = 0; i < n; i++) {
            bal += nums[i] < k ? -1 : 1;
            res += cnt[bal] + cnt[bal - 1];
        }
        return res;
    }
};
