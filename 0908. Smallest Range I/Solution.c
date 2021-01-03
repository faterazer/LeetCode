#include <math.h>

int smallestRangeI(int *A, int ASize, int K)
{
    int smallest = A[0], biggest = A[0];
    for (int i = 1; i < ASize; i++) {
        smallest = fmin(smallest, A[i]);
        biggest = fmax(biggest, A[i]);
    }
    return fmax(biggest - smallest - 2 * K, 0);
}
