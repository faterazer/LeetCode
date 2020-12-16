#include <stdlib.h>

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** largeGroupPositions(char *s, int *returnSize, int **returnColumnSizes)
{
    int SIZE = 128;
    int **ret = (int**)malloc(sizeof(int*) * SIZE);
    *returnColumnSizes = (int*)malloc(sizeof(int) * SIZE);
    *returnSize = 0;
    for (int i = 0, j = 0; s[j]; i = j) {
        while (s[j] && s[j] == s[i])
            j++;
        if (j - i >= 3) {
            ret[*returnSize] = (int*)malloc(sizeof(int) * 2);
            ret[*returnSize][0] = i;
            ret[*returnSize][1] = j - 1;
            (*returnColumnSizes)[(*returnSize)++] = 2;
        }
    }
    return ret;
}
