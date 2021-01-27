#include <math.h>
#include <stdlib.h>

void swap(int *x, int *y)
{
    int tmp = *x;
    *x = *y;
    *y = tmp;
}


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* numMovesStones(int a, int b, int c, int *returnSize)
{
    if (a > b)
        swap(&a, &b);
    if (b > c)
        swap(&b, &c);
    if (a > b)
        swap(&a, &b);
    int *ret = (int*)malloc(sizeof(int) * 2);
    *returnSize = 2;
    if (c - a == 2) {
        ret[0] = ret[1] = 0;
    }
    else {
        ret[0] = fmin(b - a, c - b) <= 2 ? 1 : 2;
        ret[1] = c - a - 2;
    }
    return ret;
}
