#include <string>
using namespace std;

class Solution {
public:
    int longestValidParentheses(string s)
    {
        int l_cnt = 0, r_cnt = 0, res = 0;
        for (const char& c : s) {
            if (c == '(') {
                ++l_cnt;
            } else {
                ++r_cnt;
            }
            if (l_cnt < r_cnt)
                l_cnt = r_cnt = 0;
            else if (l_cnt == r_cnt)
                res = max(res, 2 * l_cnt);
        }
        l_cnt = r_cnt = 0;
        for (int i = s.size() - 1; i >= 0; --i) {
            if (s[i] == '(') {
                ++l_cnt;
            } else {
                ++r_cnt;
            }
            if (l_cnt > r_cnt)
                l_cnt = r_cnt = 0;
            else if (l_cnt == r_cnt)
                res = max(res, 2 * l_cnt);
        }
        return res;
    }
};
