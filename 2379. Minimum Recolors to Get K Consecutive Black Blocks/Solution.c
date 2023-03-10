#include <math.h>

int minimumRecolors(char* blocks, int k)
{
    int cnt_W = 0, i = 0;
    for (; i < k; i++)
        cnt_W += blocks[i] == 'W';
    int res = cnt_W;
    for (; blocks[i]; i++) {
        cnt_W -= blocks[i - k] == 'W';
        cnt_W += blocks[i] == 'W';
        res = fmin(res, cnt_W);
    }
    return res;
}
