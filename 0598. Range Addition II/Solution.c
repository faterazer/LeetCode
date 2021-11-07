#include <math.h>

int maxCount(int m, int n, int** ops, int opsSize, int* opsColSize)
{
    for (int i = 0; i < opsSize; i++) {
        m = fmin(m, ops[i][0]);
        n = fmin(n, ops[i][1]);
    }
    return m * n;
}
