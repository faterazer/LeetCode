#include <math.h>

int maxLengthBetweenEqualCharacters(char *s)
{
    int memo[26] = {0}, res = -1;
    for (int i = 0; s[i]; i++) {
        if (memo[s[i] - 'a'])
            res = fmax(res, i - memo[s[i] - 'a']);
        else
            memo[s[i] - 'a'] = i + 1;
    }
    return res;
}
