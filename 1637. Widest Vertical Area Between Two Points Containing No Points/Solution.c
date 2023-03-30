#include <math.h>
#include <stdlib.h>

int cmp(const void* pa, const void* pb)
{
    int *a = *(int**)pa, *b = *(int**)pb;
    return a[0] - b[0];
}

int maxWidthOfVerticalArea(int** points, int pointsSize, int* pointsColSize)
{
    qsort(points, pointsSize, sizeof(int*), cmp);
    int res = 0;
    for (int i = 1; i < pointsSize; i++)
        res = fmax(res, points[i][0] - points[i - 1][0]);
    return res;
}
