#include <string.h>

int countGoodSubstrings(char *s)
{
    int res = 0, n = strlen(s);
    for (int i = 2; i < n; i++)
        if (s[i - 2] != s[i - 1] && s[i - 2] != s[i] && s[i - 1] != s[i])
            res++;
    return res;
}
