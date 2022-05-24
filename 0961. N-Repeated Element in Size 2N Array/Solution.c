#include <stdlib.h>
#include <time.h>

int repeatedNTimes_MK1(int* A, int ASize)
{
    for (int i = 2; i < ASize; i++)
        if (A[i] == A[i - 1] || A[i] == A[i - 2])
            return A[i];
    return A[0];
}

int repeatedNTimes_MK2(int* A, int ASize)
{
    srand(time(NULL));
    for (int i = 0; i < 10; ++i) {
        int x = rand() % ASize, y = rand() % ASize;
        if (x != y && A[x] == A[y])
            return A[x];
    }
    return repeatedNTimes_MK1(A, ASize);
}
