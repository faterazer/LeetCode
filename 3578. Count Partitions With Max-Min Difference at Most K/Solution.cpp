#include <deque>
#include <vector>
using namespace std;

class Solution {
public:
    int countPartitions(vector<int>& nums, int k)
    {
        int n = nums.size();
        deque<int> min_queue, max_queue;
        vector<int> dp(n + 1);
        dp[0] = 1;
        long long window_sum = 0;
        int left = 0;
        for (int i = 0; i < n; ++i) {
            window_sum += dp[i];
            while (!min_queue.empty() && nums[min_queue.back()] >= nums[i])
                min_queue.pop_back();
            min_queue.emplace_back(i);
            while (!max_queue.empty() && nums[max_queue.back()] <= nums[i])
                max_queue.pop_back();
            max_queue.emplace_back(i);
            while (nums[max_queue.front()] - nums[min_queue.front()] > k) {
                window_sum -= dp[left++];
                if (min_queue.front() < left)
                    min_queue.pop_front();
                if (max_queue.front() < left)
                    max_queue.pop_front();
            }
            dp[i + 1] = window_sum % MOD;
        }
        return dp.back();
    }

private:
    static constexpr int MOD = 1'000'000'007;
};
