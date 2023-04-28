#include <numeric>
#include <vector>
using namespace std;

class Solution {
public:
    int maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen)
    {
        return max(helper(nums, firstLen, secondLen), helper(nums, secondLen, firstLen));
    }

private:
    int helper(const vector<int>& nums, int firstLen, int secondLen)
    {
        int first_sum = accumulate(nums.begin(), nums.begin() + firstLen, 0);
        int max_first_sum = first_sum;
        int second_sum = accumulate(nums.begin() + firstLen, nums.begin() + firstLen + secondLen, 0);
        int res = max_first_sum + second_sum;
        for (size_t i = firstLen; i + secondLen < nums.size(); i++) {
            first_sum += nums[i] - nums[i - firstLen];
            max_first_sum = max(max_first_sum, first_sum);
            second_sum += nums[i + secondLen] - nums[i];
            res = max(res, max_first_sum + second_sum);
        }
        return res;
    }
};
