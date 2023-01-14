#include <limits.h>
#include <math.h>

int rearrangeCharacters(char* s, char* target)
{
    int cnt1[26] = { 0 }, cnt2[26] = { 0 };
    for (int i = 0; s[i]; i++)
        cnt1[s[i] - 'a']++;
    for (int i = 0; target[i]; i++)
        cnt2[target[i] - 'a']++;

    int res = INT_MAX;
    for (int i = 0; i < 26; i++)
        if (cnt2[i])
            res = fmin(res, cnt1[i] / cnt2[i]);
    return res;
}
