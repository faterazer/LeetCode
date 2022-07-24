#include <string.h>

int numMatchingSubseq(char* s, char** words, int wordsSize)
{
    int sn = strlen(s);
    int dp[sn + 1][26];
    for (int i = 0; i < 26; ++i)
        dp[sn][i] = -1;
    for (int i = sn - 1; i >= 0; --i) {
        memcpy(dp[i], dp[i + 1], sizeof(int) * 26);
        dp[i][s[i] - 'a'] = i + 1;
    }

    int res = 0;
    for (int i = 0; i < wordsSize; ++i) {
        int idx = 0;
        for (int j = 0; words[i][j]; ++j) {
            idx = dp[idx][words[i][j] - 'a'];
            if (idx == -1)
                break;
        }
        if (idx != -1)
            ++res;
    }
    return res;
}
