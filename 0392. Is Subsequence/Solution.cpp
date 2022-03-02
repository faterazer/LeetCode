#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    bool isSubsequence_MK1(string s, string t)
    {
        size_t si = 0, ti = 0;
        for (; ti < t.size(); ti++)
            if (s[si] == t[ti])
                si++;
        return si == s.size();
    }

    bool isSubsequence_MK2(string s, string t)
    {
        int sn = s.size(), tn = t.size();
        vector<vector<int>> dp(tn + 1, vector<int>(26, tn));
        for (int i = tn - 1; i >= 0; i--) {
            for (int j = 0; j < 26; j++) {
                if ('a' + j == t[i])
                    dp[i][j] = i;
                else
                    dp[i][j] = dp[i + 1][j];
            }
        }
        int ti = 0;
        for (int si = 0; si < sn; si++) {
            if (dp[ti][s[si] - 'a'] == tn)
                return false;
            ti = dp[ti][s[si] - 'a'] + 1;
        }
        return true;
    }
};
