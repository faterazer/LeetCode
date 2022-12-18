#include <stack>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures)
    {
        int n = temperatures.size();
        stack<int> mono_stk;
        vector<int> res(n, 0);
        for (int i = 0; i < n; i++) {
            while (!mono_stk.empty() && temperatures[mono_stk.top()] < temperatures[i]) {
                res[mono_stk.top()] = i - mono_stk.top();
                mono_stk.pop();
            }
            mono_stk.emplace(i);
        }
        return res;
    }
};
