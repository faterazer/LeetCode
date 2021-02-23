#include <math.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* replaceElements(int *arr, int arrSize, int *returnSize)
{
    int max = -1, tmp;
    *returnSize = arrSize;
    for (int i = arrSize - 1; i >= 0; i--) {
        tmp = arr[i];
        arr[i] = max;
        max = fmax(max, tmp);
    }
    return arr;
}
