#include <stdlib.h>
#include <string.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *diStringMatch(char *S, int *returnSize)
{
    int N = strlen(S);
    int *ret = (int*)malloc(sizeof(int) * (N + 1));
    *returnSize = 0;
    int l = 0, r = N;
    for (int i = 0; i < N; i++)
        ret[(*returnSize)++] = S[i] == 'I' ? l++ : r--;
    ret[(*returnSize)++] = l;
    return ret;
}
