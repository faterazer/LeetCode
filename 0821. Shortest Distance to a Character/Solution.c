#include <math.h>
#include <stdlib.h>
#include <string.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* shortestToChar(char *S, char C, int *returnSize)
{
    int n = strlen(S);
    int *ret = (int*)malloc(sizeof(int) * n);
    *returnSize = n;
    char *lastC = strchr(S, C);
    for (int i = 0; i <= lastC - S; i++)
        ret[i] = lastC - S - i;
    for (char *cur = strchr(S + 1, C); cur; lastC = cur, cur = strchr(cur + 1, C)) {
        int l = lastC - S, r = cur - S;
        for (int j = l; j <= r; j++)
            ret[j] = fmin(j - l, r - j);
    }
    for (int i = lastC - S; i < n; i++)
        ret[i] = i - (lastC - S);
    return ret;
}
