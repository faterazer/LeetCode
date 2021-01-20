#include <stdlib.h>

void reverse(int *arr, int n)
{
    int tmp, m = n / 2;
    for (int i = 0; i < m; i++) {
        tmp = arr[i];
        arr[i] = arr[n - 1 - i];
        arr[n - 1- i] = tmp;
    }
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* addToArrayForm(int *A, int ASize, int K, int *returnSize)
{
    reverse(A, ASize);
    for (int i = 0; i < ASize && K; i++, K /= 10) {
        K += A[i];
        A[i] = K % 10;
    }
    for (*returnSize = ASize; K; K /= 10) {
        A = (int*)realloc(A, sizeof(int) * ((*returnSize) + 1));
        A[(*returnSize)++] = K % 10;
    }
    reverse(A, *returnSize);
    return A;
}
