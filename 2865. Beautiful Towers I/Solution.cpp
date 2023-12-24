#include <stack>
#include <vector>
using namespace std;

class Solution {
public:
    long long maximumSumOfHeights(vector<int>& maxHeights)
    {
        int n = maxHeights.size();
        vector<long long> suf(n + 1, 0);
        stack<int> stk;
        stk.emplace(n);
        for (int i = n - 1; i >= 0; i--) {
            suf[i] = suf[i + 1];
            while (stk.size() > 1 && maxHeights[i] <= maxHeights[stk.top()]) {
                int j = stk.top();
                stk.pop();
                suf[i] -= static_cast<long long>(maxHeights[j]) * (stk.top() - j);
            }
            suf[i] += static_cast<long long>(maxHeights[i]) * (stk.top() - i);
            stk.emplace(i);
        }

        long long res = 0;
        stk = stack<int>();
        stk.emplace(-1);
        long long pre = 0;
        for (int i = 0; i < n; i++) {
            while (stk.size() > 1 && maxHeights[i] <= maxHeights[stk.top()]) {
                int j = stk.top();
                stk.pop();
                pre -= static_cast<long long>(maxHeights[j]) * (j - stk.top());
            }
            pre += static_cast<long long>(maxHeights[i]) * (i - stk.top());
            stk.emplace(i);
            res = max(res, pre + suf[i + 1]);
        }
        return res;
    }
};
