#include <algorithm>
#include <ranges>
#include <vector>
using namespace std;

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k)
    {
        int mx = ranges::max(nums), mx_cnt = 0, i = 0;
        long long ans = 0;
        for (int x : nums) {
            mx_cnt += x == mx;
            while (mx_cnt == k)
                mx_cnt -= nums[i++] == mx;
            ans += i;
        }
        return ans;
    }
};
