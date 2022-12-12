#include <limits.h>
#include <math.h>

int beautySum(char* s)
{
    int res = 0;
    for (int i = 0; s[i]; i++) {
        int cnt[26] = { 0 };
        for (int j = i; s[j]; j++) {
            ++cnt[s[j] - 'a'];
            int mx = 0, mn = INT_MAX;
            for (int k = 0; k < 26; k++) {
                mx = fmax(mx, cnt[k]);
                if (cnt[k] > 0)
                    mn = fmin(mn, cnt[k]);
            }
            res += mx - mn;
        }
    }
    return res;
}
