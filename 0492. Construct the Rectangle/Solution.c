/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

#include <math.h>
#include <stdlib.h>

int* constructRectangle(int area, int *returnSize)
{
    int w = sqrt(area);
    while (area % w)
        w--;
    int *ret = (int *)malloc(sizeof(int) * 2);
    ret[0] = area / w;
    ret[1] = w;
    *returnSize = 2;
    return ret;
}
