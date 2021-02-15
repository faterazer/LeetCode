#include <stdlib.h>

int cmp(const void *a, const void *b)
{
    return *(int*)a - *(int*)b;
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** minimumAbsDifference(int *arr, int arrSize, int *returnSize, int **returnColumnSizes)
{
    qsort(arr, arrSize, sizeof(int), cmp);
    int diff = INT_MAX, size = 0;
    for (int i = 1; i < arrSize; i++) {
        if (arr[i] - arr[i - 1] < diff) {
            diff = arr[i] - arr[i - 1];
            size = 1;
        }
        else
            size++;
    }
    *returnColumnSizes = (int*)malloc(sizeof(int) * size);
    int **res = (int**)malloc(sizeof(int*) * size);
    *returnSize = 0;
    for (int i = 1; i < arrSize; i++) {
        if (arr[i] - arr[i - 1] == diff) {
            res[*returnSize] = (int*)malloc(sizeof(int) * 2);
            res[*returnSize][0] = arr[i - 1];
            res[*returnSize][1] = arr[i];
            (*returnColumnSizes)[(*returnSize)++] = 2;
        }
    }
    return res;
}
