#include <string>
using namespace std;

class Solution {
public:
    int findTheLongestBalancedSubstring(string s)
    {
        int res = 0;
        size_t i = 0;
        while (i < s.size()) {
            int zero_cnt = 0, one_cnt = 0;
            for (; i < s.size() && s[i] == '0'; ++i)
                ++zero_cnt;
            for (; i < s.size() && s[i] == '1'; ++i)
                ++one_cnt;
            res = max(res, 2 * min(zero_cnt, one_cnt));
        }
        return res;
    }
};
