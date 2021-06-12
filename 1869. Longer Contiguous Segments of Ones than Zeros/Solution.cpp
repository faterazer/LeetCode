#include <string>
using namespace std;

class Solution
{
public:
    bool checkZeroOnes(string s)
    {
        int res[2] = {0}, i = 0;
        for (int j = 1; j <= s.size(); j++) {
            if (j == s.size() || s[j] != s[i]) {
                if (s[i] == '0')
                    res[0] = max(res[0], j - i);
                else
                    res[1] = max(res[1], j - i);
                i = j;
            }
        }
        return res[1] > res[0];
    }
};
