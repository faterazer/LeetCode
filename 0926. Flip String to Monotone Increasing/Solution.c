#include <math.h>

int minFlipsMonoIncr(char* s)
{
    int cnt_ones = 0, cnt_flips = 0;
    while (*s) {
        if (*s++ == '1')
            ++cnt_ones;
        else
            cnt_flips = fmin(cnt_flips + 1, cnt_ones);
    }
    return cnt_flips;
}
