#include <string>
using namespace std;

class Solution {
public:
    int longestContinuousSubstring(string s)
    {
        int res = 1, cur = 1;
        for (size_t i = 1; i < s.size(); ++i) {
            cur = s[i] == s[i - 1] + 1 ? cur + 1 : 1;
            res = max(res, cur);
        }
        return res;
    }
};
