#include <stdbool.h>
#include <stdlib.h>

int cmp(const void *a, const void *b)
{
    return *(int*)a - *(int*)b;
}

bool canBeEqual(int *target, int targetSize, int *arr, int arrSize)
{
    qsort(target, targetSize, sizeof(int), cmp);
    qsort(arr, arrSize, sizeof(int), cmp);
    for (int i = 0; i < targetSize; i++)
        if (target[i] != arr[i])
            return false;
    return true;
}
