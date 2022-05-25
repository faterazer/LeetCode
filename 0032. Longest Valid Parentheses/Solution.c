#include <math.h>

int longestValidParentheses(char* s)
{
    int l_cnt = 0, r_cnt = 0, res = 0, i = 0;
    for (; s[i]; ++i) {
        if (s[i] == '(')
            ++l_cnt;
        else
            ++r_cnt;
        if (l_cnt == r_cnt)
            res = fmax(res, 2 * l_cnt);
        else if (l_cnt < r_cnt)
            l_cnt = r_cnt = 0;
    }
    l_cnt = 0, r_cnt = 0;
    for (i = i - 1; i >= 0; --i) {
        if (s[i] == '(')
            ++l_cnt;
        else
            ++r_cnt;
        if (l_cnt == r_cnt)
            res = fmax(res, 2 * l_cnt);
        else if (l_cnt > r_cnt)
            l_cnt = r_cnt = 0;
    }
    return res;
}
