#include <stdlib.h>

int cmp(const void *a, const void *b)
{
    return *(int*)a - *(int*)b;
}

int findContentChildren(int *g, int gSize, int *s, int sSize)
{
    qsort(g, gSize, sizeof(int), cmp);
    qsort(s, sSize, sizeof(int), cmp);
    int gi = 0;
    for (int i = 0; i < sSize && gi < gSize; i++)
        if (s[i] >= g[gi])
            gi++;
    return gi;
}
