#include <vector>
using namespace std;

class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums)
    {
        int min_sum = 0, max_sum = 0, ans = 0;
        for (int x : nums) {
            min_sum = min(min_sum, 0) + x;
            max_sum = max(max_sum, 0) + x;
            ans = max(ans, max(-min_sum, max_sum));
        }
        return ans;
    }
};
