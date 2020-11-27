#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* numberOfLines(int *widths, int widthsSize, char *S, int *returnSize)
{
    int *res = (int*)malloc(sizeof(int) * 2);
    *returnSize = 2;

    int lines = 1, width = 0;
    for (int i = 0; S[i]; i++) {
        if (width + widths[S[i] - 'a'] > 100) {
            width = 0;
            lines++;
        }
        width += widths[S[i] - 'a'];
    }
    res[0] = lines;
    res[1] = width;
    return res;
}
