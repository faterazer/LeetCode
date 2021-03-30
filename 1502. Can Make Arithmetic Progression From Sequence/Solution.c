#include <stdbool.h>
#include <stdlib.h>

int comp(const void *a, const void *b)
{
    return *(int*)a - *(int*)b;
}

bool canMakeArithmeticProgression(int *arr, int arrSize)
{
    int diff;
    qsort(arr, arrSize, sizeof(int), comp);
    diff = arr[1] - arr[0];
    for (int i = 2; i < arrSize; i++)
        if (arr[i] - arr[i - 1] != diff)
            return false;
    return true;
}
