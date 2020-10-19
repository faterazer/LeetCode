#include <stdbool.h>
#include <string.h>

bool backspaceCompare(char *S, char *T)
{
    int skip_s = 0, skip_t = 0;
    for (int sp = strlen(S) - 1, tp = strlen(T) - 1; sp >= 0 || tp >= 0; sp--, tp--) {
        for (; sp >= 0 && (S[sp] == '#' || skip_s); sp--) {
            if (S[sp] == '#')
                skip_s++;
            else
                skip_s--;
        }
        for (; tp >= 0 && (T[tp] == '#' || skip_t); tp--) {
            if (T[tp] == '#')
                skip_t++;
            else
                skip_t--;
        }
        if ((sp >= 0) != (tp >= 0) || (sp >= 0 && tp >= 0 && S[sp] != T[tp]))
            return false;

    }
    return true;
}
