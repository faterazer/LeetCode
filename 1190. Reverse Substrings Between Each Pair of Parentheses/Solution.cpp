#include <ranges>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string reverseParentheses(string s)
    {
        int n = s.size();
        vector<int> stk, pair(n);
        for (int i = 0; i < n; i++) {
            if (s[i] == '(')
                stk.emplace_back(i);
            else if (s[i] == ')') {
                int j = stk.back();
                stk.pop_back();
                pair[i] = j;
                pair[j] = i;
            }
        }

        string res;
        for (int i = 0, d = 1; i < n; i += d) {
            if (s[i] == '(' || s[i] == ')') {
                i = pair[i];
                d = -d;
            } else
                res.push_back(s[i]);
        }
        return res;
    }
};
