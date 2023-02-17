#include <math.h>

int balancedString(char* s)
{
    int cnt['X'] = { 0 }, n;
    for (n = 0; s[n]; n++)
        cnt[s[n]]++;

    int res = n, limit = n / 4, i = 0;
    if (cnt['Q'] == limit && cnt['W'] == limit && cnt['E'] == limit)
        return 0;
    for (int j = 0; j < n; j++) {
        cnt[s[j]]--;
        while (cnt['Q'] <= limit && cnt['W'] <= limit && cnt['E'] <= limit && cnt['R'] <= limit) {
            res = fmin(res, j - i + 1);
            cnt[s[i++]]++;
        }
    }
    return res;
}
