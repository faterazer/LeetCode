#include <math.h>

int findSubstringInWraproundString(char* p)
{
    int cnt[26] = {0}, len = 0;
    for (int i = 0; p[i]; ++i) {
        if (i && (p[i] - p[i - 1] + 26) % 26 == 1)
            ++len;
        else
            len = 1;
        cnt[p[i] - 'a'] = fmax(cnt[p[i] - 'a'], len);
    }
    int res = 0;
    for (int i = 0; i < 26; ++i)
        res += cnt[i];
    return res;
}
