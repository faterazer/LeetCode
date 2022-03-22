#include <math.h>
#include <stdlib.h>

char* getSmallestString(int n, int k)
{
    char *res = (char*)malloc(sizeof(char) * (n + 1));
    for (int i = 0; i < n; ++i)
        res[i] = 'a';
    res[n] = '\0';
    k -= n;
    while (k > 0) {
        res[--n] += fmin(25, k);
        k -= 25;
    }
    return res;
}
