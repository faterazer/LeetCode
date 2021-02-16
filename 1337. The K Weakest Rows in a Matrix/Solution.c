#include <stdlib.h>

int countOnes(int *arr, int n)
{
    int l = 0, r = n, m;
    while (l < r) {
        m = l + ((r - l) >> 1);
        if (arr[m] == 1)
            l = m + 1;
        else
            r = m;
    }
    return l;
}

int cmp(const void *a, const void *b)
{
    int *ap = (int*)a;
    int *bp = (int*)b;
    if (ap[0] != bp[0])
        return ap[0] - bp[0];
    return ap[1] - bp[1];
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* kWeakestRows(int **mat, int matSize, int *matColSize, int k, int *returnSize)
{
    int m = matSize, n = matColSize[0];
    int buff[m][2];
    for (int i = 0; i < matSize; i++) {
        buff[i][0] = countOnes(mat[i], n);
        buff[i][1] = i;
    }
    qsort(buff, m, sizeof(buff[0]), cmp);
    int *ret = (int*)malloc(sizeof(int) * k);
    *returnSize = k;
    for (int i = 0; i < k; i++)
        ret[i] = buff[i][1];
    return ret;
}
