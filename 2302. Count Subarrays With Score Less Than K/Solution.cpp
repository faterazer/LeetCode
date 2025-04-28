#include <vector>
using namespace std;

class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k)
    {
        int i = 0, n = nums.size();
        long long sum = 0, ans = 0;
        for (int j = 0; j < n; ++j) {
            sum += nums[j];
            while (sum * (j - i + 1) >= k)
                sum -= nums[i++];
            ans += j - i + 1;
        }
        return ans;
    }
};
