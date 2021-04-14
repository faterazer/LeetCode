#include <string>
using namespace std;

class Solution
{
public:
    string modifyString(string s)
    {
        char sentinel = 'a' - 1, lc, rc;
        for (size_t i = 0; i < s.size(); i++) {
            if (s[i] != '?')
                continue;
            lc = i == 0 ? sentinel : s[i - 1];
            rc = i == s.size() - 1 || s[i + 1] == '?' ? sentinel : s[i + 1];
            for (s[i] = 'a'; s[i] <= 'z' && (s[i] == lc || s[i] == rc); s[i]++)
                ;
        }
        return s;
    }
};
