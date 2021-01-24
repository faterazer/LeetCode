#include <math.h>
#include <stdlib.h>

int cmp(const void *a, const void *b)
{
    return *(int*)a - *(int*)b;
}

int largestSumAfterKNegations(int *A, int ASize, int K)
{
    qsort(A, ASize, sizeof(int), cmp);
    int i = 0;
    for (; i < ASize && A[i] < 0 && K; i++, K--)
        A[i] *= -1;
    int min = i > 0 && i < ASize ? fmin(A[i], A[i - 1]) : fmin(A[0], A[ASize - 1]);
    int sum = 0;
    for (int i = 0; i < ASize; i++)
        sum += A[i];
    return sum - (K % 2) * min * 2;
}
