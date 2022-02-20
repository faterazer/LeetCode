#include <math.h>

int lengthOfLongestSubstring(char* s)
{
    int dict[256] = { 0 };
    for (int i = 0; i < 256; i++)
        dict[i] = -1;
    int beg = -1, res = 0;
    for (int i = 0; s[i]; i++) {
        if (dict[s[i]] > beg)
            beg = dict[s[i]];
        dict[s[i]] = i;
        res = fmax(res, i - beg);
    }
    return res;
}
