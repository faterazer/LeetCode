#include <stdlib.h>

int maxSideLength(int** mat, int matSize, int* matColSize, int threshold)
{
    int m = matSize, n = matColSize[0];
    int* pre_sum = (int*)calloc((m + 1) * (n + 1), sizeof(int));
    if (!pre_sum)
        return 0;

    #define P(r, c) pre_sum[(r) * (n + 1) + (c)]

    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
            P(i + 1, j + 1) = P(i + 1, j) + P(i, j + 1) - P(i, j) + mat[i][j];

    int max_side = 0;
    for (int i = 0; i < m; ++i) {
        int r1 = i;
        for (int j = 0; j < n; ++j) {
            int c1 = j;
            while (i + max_side < m && j + max_side < n) {
                int r2 = i + max_side + 1, c2 = j + max_side + 1;
                int cur_sum = P(r2, c2) - P(r2, c1) - P(r1, c2) + P(r1, c1);
                if (cur_sum <= threshold)
                    ++max_side;
                else
                    break;
            }
        }
    }
    return max_side;
}
