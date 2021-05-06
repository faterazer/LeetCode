#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* decode(int *encoded, int encodedSize, int first, int *returnSize)
{
    int *res = (int*)malloc(sizeof(int) * (encodedSize + 1));
    *returnSize = encodedSize + 1;
    res[0] = first;
    for (int i = 0; i < encodedSize; i++)
        res[i + 1] = res[i] ^ encoded[i];
    return res;
}
