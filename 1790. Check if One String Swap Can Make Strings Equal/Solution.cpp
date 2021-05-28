#include <string>
using namespace std;

class Solution
{
public:
    bool areAlmostEqual(string s1, string s2)
    {
        int cnt = 0, idx[2];
        for (size_t i = 0; i < s1.size(); i++) {
            if (s1[i] != s2[i]) {
                if (cnt < 2)
                    idx[cnt++] = i;
                else
                    return false;
            }
        }
        return !cnt || (cnt == 2 && s1[idx[0]] == s2[idx[1]] && s1[idx[1]] == s2[idx[0]]);
    }
};
