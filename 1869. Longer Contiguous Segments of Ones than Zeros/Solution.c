#include <math.h>
#include <stdbool.h>

bool checkZeroOnes(char *s)
{
    int res[2] = {0}, i, j;
    for (i = 0, j = 1; s[j]; j++) {
        if (s[j] == s[i])
            continue;
        if (s[i] == '0')
            res[0] = fmax(res[0], j - i);
        else
            res [1] = fmax(res[1], j - i);
        i = j;
    }
    if (s[i] == '0')
        res[0] = fmax(res[0], j - i);
    else
        res[1] = fmax(res[1], j - i);
    return res[1] > res[0];
}
