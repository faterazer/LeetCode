#include <functional>
#include <ranges>
#include <vector>
using namespace std;

class Solution {
public:
    int maxDivScore(vector<int>& nums, vector<int>& divisors)
    {
        ranges::sort(nums, greater());
        int dup_cnt = 0;
        for (size_t i = 1; i < nums.size(); i++)
            dup_cnt += nums[i] == nums[i - 1];

        ranges::sort(divisors);

        int res = 0, max_score = -1;
        for (int divisor : divisors) {
            if (max_score - dup_cnt >= nums[0] / divisor)
                break;

            int score = 0;
            for (int n : nums) {
                if (n < divisor)
                    break;
                score += n % divisor == 0;
            }

            if (score > max_score) {
                max_score = score;
                res = divisor;
            }
        }
        return res;
    }
};
