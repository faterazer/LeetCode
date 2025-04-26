#include <vector>
using namespace std;

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK)
    {
        int beg = -1, min_i = -1, max_i = -1;
        long long ans = 0;
        for (size_t i = 0; i < nums.size(); ++i) {
            int x = nums[i];
            if (x == minK)
                min_i = i;
            if (x == maxK)
                max_i = i;
            if (x < minK || x > maxK)
                beg = i;
            ans += max(min(min_i, max_i) - beg, 0);
        }
        return ans;
    }
};
