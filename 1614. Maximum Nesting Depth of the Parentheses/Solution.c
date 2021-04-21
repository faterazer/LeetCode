#include <math.h>

int maxDepth(char *s)
{
    int lp = 0, res = 0;
    for (int i = 0; s[i]; i++)
        if (s[i] == '(')
            res = fmax(res, ++lp);
        else if (s[i] == ')')
            lp--;
    return res;
}
