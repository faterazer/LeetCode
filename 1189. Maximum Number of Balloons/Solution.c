#include <limits.h>
#include <math.h>

int maxNumberOfBalloons(char *text)
{
    int count[26] = {0};
    for (int i = 0; text[i]; i++)
        count[text[i] - 'a']++;
    int res = INT_MAX;
    res = fmin(res, count[1]);
    res = fmin(res, count[0]);
    res = fmin(res, count[11] / 2);
    res = fmin(res, count[14] / 2);
    res = fmin(res, count[13]);
    return res;
}
