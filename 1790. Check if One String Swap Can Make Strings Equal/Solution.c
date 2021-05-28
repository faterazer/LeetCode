#include <stdbool.h>

bool areAlmostEqual(char *s1, char *s2)
{
    int cnt = 0, idx[2];
    for (int i = 0; s1[i]; i++) {
        if (s1[i] != s2[i]) {
            if (cnt < 2)
                idx[cnt++] = i;
            else
                return false;
        }
    }
    return !cnt || (cnt == 2 && s1[idx[0]] == s2[idx[1]] && s1[idx[1]] == s2[idx[0]]);
}
