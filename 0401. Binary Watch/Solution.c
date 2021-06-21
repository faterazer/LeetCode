#include <stdio.h>
#include <stdlib.h>

int count(int x)
{
    int res = 0;
    for ( ; x; x &= x - 1)
        res++;
    return res;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** readBinaryWatch(int turnedOn, int *returnSize)
{
    char **res = (char**)malloc(sizeof(char*) * 256);
    *returnSize = 0;
    for (int hour = 0; hour < 12; hour++) {
        for (int minute = 0; minute < 60; minute++) {
            if (count(hour) + count(minute) == turnedOn) {
                res[*returnSize] = (char*)malloc(sizeof(char) * 6);
                sprintf(res[(*returnSize)++], "%d:%02d", hour, minute);
            }
        }
    }
    res = (char**)realloc(res, sizeof(char*) * (*returnSize));
    return res;
}
