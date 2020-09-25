#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp(const void *a, const void *b)
{
    return -(*(int*)a - *(int*)b);
}

char* largestTimeFromDigits(int *arr, int arrSize)
{
    qsort(arr, arrSize, sizeof(int), cmp);
    char *ret = (char*)malloc(sizeof(char) * 6);
    memset(ret, '\0', 6);
    for (int i = 0; i < arrSize; i++) {
        for (int j = 0; j < arrSize; j++) {
            for (int k = 0; k < arrSize; k++) {
                if (i == j || i == k || j == k)
                    continue;
                if ((arr[i] < 2 || (arr[i] == 2 && arr[j] < 4)) && arr[k] < 6) {
                    sprintf(ret, "%d%d:%d%d\0", arr[i], arr[j], arr[k], arr[6 - i - j - k]);
                    return ret;
                }
            }
        }
    }
    return ret;
}
