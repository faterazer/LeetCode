#include <vector>
using namespace std;

class Solution
{
public:
    int maxAscendingSum(vector<int> &nums)
    {
        int max_sum = nums[0], cur = nums[0];
        for (size_t i = 1; i < nums.size(); i++) {
            if (nums[i] <= nums[i - 1]) {
                max_sum = max(max_sum, cur);
                cur = 0;
            }
            cur += nums[i];
        }
        return max(max_sum, cur);
    }
};
