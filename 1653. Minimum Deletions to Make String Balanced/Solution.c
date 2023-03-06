#include <math.h>

int minimumDeletions_MK1(char* s)
{
    int del = 0;
    for (int i = 0; s[i]; i++)
        del += s[i] == 'a';
    int res = del;
    for (int i = 0; s[i]; i++) {
        del += (s[i] - 'a') * 2 - 1;
        res = fmin(res, del);
    }
    return res;
}

int minimumDeletions_MK2(char* s)
{
    int res = 0, cnt_b = 0;
    for (int i = 0; s[i]; i++) {
        if (s[i] == 'a')
            res = fmin(res + 1, cnt_b);
        else
            ++cnt_b;
    }
    return res;
}
