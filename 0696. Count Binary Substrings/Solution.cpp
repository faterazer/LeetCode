#include <string>
using namespace std;

class Solution
{
public:
    int countBinarySubstrings(string s)
    {
        int prev = 0, cur = 1, ans = 0;
        for (size_t i = 1; i < s.size(); i++) {
            if (s[i] != s[i - 1]) {
                ans += min(prev, cur);
                prev = cur;
                cur = 0;
            }
            cur += 1;
        }
        return ans + min(prev, cur);
    }
};
