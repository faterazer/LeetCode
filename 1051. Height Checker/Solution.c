#include <memory.h>
#include <stdlib.h>

int cmp(const void *a, const void *b)
{
    return *(int*)a - *(int*)b;
}

int heightChecker(int *heights, int heightsSize)
{
    int res = 0;
    int buff[heightsSize];
    memcpy(buff, heights, sizeof(int) * heightsSize);
    qsort(buff, heightsSize, sizeof(int), cmp);
    for (int i = 0; i < heightsSize; i++)
        if (heights[i] != buff[i])
            res++;
    return res;
}
