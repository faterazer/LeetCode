#include <memory.h>

int oddCells(int n, int m, int **indices, int indicesSize, int *indicesColSize)
{
    int r[n], c[m];
    memset(r, 0, sizeof(int) * n);
    memset(c, 0, sizeof(int) * m);
    for (int i = 0; i < indicesSize; i++) {
        r[indices[i][0]] ^= 1;
        c[indices[i][1]] ^= 1;
    }
    int res = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            res += r[i] ^ c[j];
    return res;
}
