#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findClosestElements(int* arr, int arrSize, int k, int x, int* returnSize)
{
    int l = 0, r = arrSize - k;
    while (l < r) {
        int m = l + ((r - l) >> 1);
        if (x - arr[m] > arr[m + k] - x)
            l = m + 1;
        else
            r = m;
    }

    *returnSize = k;
    int* res = (int*)malloc(sizeof(int) * k);
    for (int i = r; i < r + k; ++i)
        res[i - r] = arr[i];
    return res;
}
