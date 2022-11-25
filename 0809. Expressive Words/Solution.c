#include <stdbool.h>

bool isExpressive(char* s, char* t)
{
    int si = 0, ti = 0;
    while (s[si] && t[ti]) {
        if (s[si] != t[ti])
            return false;
        int sj = si + 1;
        while (s[sj] && s[sj] == s[si])
            ++sj;
        int tj = ti + 1;
        while (t[tj] && t[tj] == t[ti])
            ++tj;

        int s_cnt = sj - si, t_cnt = tj - ti;
        if ((t_cnt < s_cnt && s_cnt < 3) || s_cnt < t_cnt)
            return false;
        si = sj;
        ti = tj;
    }
    return !s[si] && !t[ti];
}

int expressiveWords(char* s, char** words, int wordsSize)
{
    int res = 0;
    for (int i = 0; i < wordsSize; i++)
        res += isExpressive(s, words[i]);
    return res;
}
