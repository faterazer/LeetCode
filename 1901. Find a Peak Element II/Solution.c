#include <stdlib.h>
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int argmax(int* arr, int len)
{
    int idx = 0;
    for (int i = 1; i < len; i++)
        if (arr[i] > arr[idx])
            idx = i;
    return idx;
}

int* findPeakGrid(int** mat, int matSize, int* matColSize, int* returnSize)
{
    int l = 0, r = matSize - 2;
    while (l <= r) {
        int i = l + ((r - l) >> 1);
        int j = argmax(mat[i], matColSize[i]);
        if (mat[i][j] < mat[i + 1][j])
            l = i + 1;
        else
            r = i - 1;
    }
    *returnSize = 2;
    int* res = (int*)malloc(sizeof(int) * 2);
    res[0] = l;
    res[1] = argmax(mat[l], matColSize[l]);
    return res;
}
