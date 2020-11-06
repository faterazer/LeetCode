#include <stdlib.h>

int cmp(const void *a, const void *b)
{
    int left = *(int*)a, right = *(int*)b;
    int lbits = 0, rbits = 0;
    for (; left; left &= left - 1)
        lbits++;
    for (; right; right &= right - 1)
        rbits++;
    if (lbits != rbits)
        return lbits - rbits;
    return *(int*)a - *(int*)b;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *sortByBits(int *arr, int arrSize, int *returnSize)
{
    *returnSize = arrSize;
    qsort(arr, arrSize, sizeof(int), cmp);
    return arr;
}
