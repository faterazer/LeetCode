#include <memory.h>
#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* decrypt(int *code, int codeSize, int k, int *returnSize)
{
    int *res = (int*)malloc(sizeof(int) * codeSize);
    memset(res, 0, sizeof(int) * codeSize);
    *returnSize = codeSize;
    int beg = 1, end = k, sum = 0;
    if (k < 0) {
        beg = codeSize + k;
        end = codeSize - 1;
    }
    for (int i = beg; i <= end; i++)
        sum += code[i];
    for (int i = 0; i < codeSize; i++) {
        res[i] = sum;
        sum -= code[(beg++) % codeSize];
        sum += code[(++end) % codeSize];
    }
    return res;
}
