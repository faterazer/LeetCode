#include <stack>
#include <vector>
using namespace std;

class Solution {
public:
    int sumSubarrayMins(vector<int>& arr)
    {
        int P = 1e9 + 7, n = arr.size(), res = 0;
        stack<int> stk;
        vector<int> dp(n);
        for (int i = 0; i < n; i++) {
            while (!stk.empty() && arr[stk.top()] > arr[i])
                stk.pop();
            int j = stk.empty() ? -1 : stk.top();
            dp[i] = arr[i] * (i - j) + (j >= 0 ? dp[j] : 0);
            res = (res + dp[i]) % P;
            stk.emplace(i);
        }
        return res;
    }
};
