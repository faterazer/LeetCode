#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** buildArray(int *target, int targetSize, int n, int *returnSize)
{
    int i = 0;
    char **res = (char**)malloc(sizeof(char*) * n * 2);
    *returnSize = 0;
    for (int x = 1; i != targetSize; x++) {
        res[(*returnSize)++] = "Push";
        if (x != target[i])
            res[(*returnSize)++] = "Pop";
        else
            i++;
    }
    return res;
}
