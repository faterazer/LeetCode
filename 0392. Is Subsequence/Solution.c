#include <stdbool.h>
#include <string.h>

bool isSubsequence_MK1(char* s, char* t)
{
    int si = 0;
    for (int ti = 0; s[si] && t[ti]; ++ti)
        if (s[si] == t[ti])
            ++si;
    return s[si] == '\0';
}

bool isSubsequence_MK2(char* s, char* t)
{
    int tn = strlen(t);
    int dp[tn + 1][26];
    for (int i = 0; i < 26; ++i)
        dp[tn][i] = tn;
    for (int i = tn - 1; i >= 0; i--) {
        for (int j = 0; j < 26; ++j) {
            if (t[i] - 'a' == j)
                dp[i][j] = i;
            else
                dp[i][j] = dp[i + 1][j];
        }
    }
    int ti = 0;
    for (int si = 0; s[si]; ++si) {
        if (dp[ti][s[si] - 'a'] == tn)
            return false;
        ti = dp[ti][s[si] - 'a'] + 1;
    }
    return true;
}
