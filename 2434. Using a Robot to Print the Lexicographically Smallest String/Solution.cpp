#include <stack>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string robotWithString(string s)
    {
        int n = s.size();
        vector<char> suffix_min(n + 1);
        suffix_min[n] = 'z';
        for (int i = n - 1; i >= 0; --i)
            suffix_min[i] = min(suffix_min[i + 1], s[i]);

        string ans;
        stack<char> stk;
        for (int i = 0; i < n; ++i) {
            char c = s[i];
            stk.emplace(c);
            while (!stk.empty() && stk.top() <= suffix_min[i + 1]) {
                ans.push_back(stk.top());
                stk.pop();
            }
        }
        return ans;
    }
};
