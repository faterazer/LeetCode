#include <deque>
#include <stack>
#include <vector>
using namespace std;

class Solution {
public:
    int numSubmat(vector<vector<int>>& mat)
    {
        int m = mat.size(), n = mat[0].size(), ans = 0;
        vector<int> height(n, 0);
        for (int i = 0; i < m; ++i) {
            stack<int> mono_stk(deque{-1});
            for (int j = 0; j < n; ++j) {
                height[j] = mat[i][j] ? height[j] + 1 : 0;
                while (mono_stk.size() > 1 && height[j] <= height[mono_stk.top()])
                    mono_stk.pop();
                int last = mono_stk.top();
                mono_stk.emplace(j);
                mat[i][j] = height[j] * (j - last);
                if (last != -1)
                    mat[i][j] += mat[i][last];
                ans += mat[i][j];
            }
        }
        return ans;
    }
};
