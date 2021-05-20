#include <math.h>

int minOperations(char *s)
{
    int cnt1 = 0, cnt2 = 0;
    for (int i = 0; s[i]; i++) {
        if (s[i] - '0' != i % 2)
            cnt1++;
        else
            cnt2++;
    }
    return fmin(cnt1, cnt2);
}
