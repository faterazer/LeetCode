#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *mostVisited(int n, int *rounds, int roundsSize, int *returnSize)
{
    int *res = (int*)malloc(sizeof(int) * n);
    *returnSize = 0;
    int bg = rounds[0], ed = rounds[roundsSize - 1];
    if (bg <= ed) {
        for (int i = bg; i <= ed; i++)
            res[(*returnSize)++] = i;
    } else {
        for (int i = 1; i <= ed; i++)
            res[(*returnSize)++] = i;
        for (int i = bg; i <= n; i++)
            res[(*returnSize)++] = i;
    }
    return res;
}
