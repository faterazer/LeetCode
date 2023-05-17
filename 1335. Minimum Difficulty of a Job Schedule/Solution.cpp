#include <stack>
#include <vector>
using namespace std;

class Solution {
public:
    int minDifficulty(vector<int>& jobDifficulty, int d)
    {
        int n = jobDifficulty.size();
        if (n < d)
            return -1;

        vector<int> dp(n);
        for (int i = 0, max_val = 0; i < n; i++) {
            max_val = max(max_val, jobDifficulty[i]);
            dp[i] = max_val;
        }
        for (int i = 1; i < d; i++) {
            stack<pair<int, int>> stk;
            vector<int> next_dp(n);
            for (int j = i; j < n; j++) {
                int pre_min = dp[j - 1];
                while (!stk.empty() && jobDifficulty[stk.top().first] < jobDifficulty[j]) {
                    pre_min = min(pre_min, stk.top().second);
                    stk.pop();
                }
                if (stk.empty())
                    next_dp[j] = pre_min + jobDifficulty[j];
                else
                    next_dp[j] = min(pre_min + jobDifficulty[j], next_dp[stk.top().first]);
                stk.emplace(j, pre_min);
            }
            swap(dp, next_dp);
        }
        return dp[n - 1];
    }
};
