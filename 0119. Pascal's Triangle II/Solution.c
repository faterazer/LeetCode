#include <memory.h>
#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* getRow(int rowIndex, int *returnSize)
{
    *returnSize = rowIndex + 1;
    int *ret = (int *)malloc(sizeof(int) * (rowIndex + 1));
    memset(ret, 0, sizeof(int) * *returnSize);
    ret[0] = 1;
    for (int i = 1; i <= rowIndex; i++)
        for (int j = i; j > 0; j--)
            ret[j] += ret[j - 1];
    return ret;
}
