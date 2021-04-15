#include <memory.h>

int numSpecial(int **mat, int matSize, int *matColSize)
{
    int m = matSize, n = matColSize[0], res = 0;
    int rows_sum[m], cols_sum[n];
    memset(rows_sum, 0, sizeof(int) * m);
    memset(cols_sum, 0, sizeof(int) * n);   
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (mat[i][j]) {
                rows_sum[i]++;
                cols_sum[j]++;
            }
        }
    }
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            if (mat[i][j] && rows_sum[i] == 1 && cols_sum[j] == 1)
                res++;
    return res;
}
