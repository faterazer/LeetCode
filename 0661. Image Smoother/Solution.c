#include <stdlib.h>

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int **imageSmoother(int **M, int MSize, int *MColSize, int *returnSize, int **returnColumnSizes)
{
    int m = MSize, n = *MColSize;
    *returnSize = m;
    *returnColumnSizes = (int*)malloc(sizeof(int) * m);
    for (int i = 0; i < m; i++)
        (*returnColumnSizes)[i] = n;
    int dirs[8][2] = {{-1, 1}, {0, 1}, {1, 1}, {-1, 0}, {1, 0}, {-1, -1}, {0, -1}, {1, -1}};
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int sum = M[i][j], cnt = 1;
            for (int k = 0; k < 8; k++) {
                int x = i + dirs[k][0];
                int y = j + dirs[k][1];
                if (x < 0 || x >= m || y < 0 || y >= n)
                    continue;
                sum += (M[x][y] & 0xFF);
                cnt += 1;
            }
            M[i][j] |= (sum / cnt) << 8;
        }
    }

    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            M[i][j] >>= 8;
    return M;
}
