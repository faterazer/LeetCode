#include <math.h>
#include <string.h>

#define MAX_N 100000

int largestSubmatrix(int** matrix, int matrixSize, int* matrixColSize)
{
    int m = matrixSize, n = matrixColSize[0];
    int heights[MAX_N] = {0}, ids[MAX_N], non_zeros[MAX_N];
    int result = 0;
    for (int i = 0; i < n; ++i)
        ids[i] = i;
    for (int i = 0; i < m; ++i) {
        int p = 0, q = 0;
        for (int k = 0; k < n; ++k) {
            int j = ids[k];
            if (matrix[i][j]) {
                ++heights[j];
                non_zeros[q++] = j;
            } else {
                heights[j] = 0;
                ids[p++] = j;
            }
        }

        for (int j = p; j < n; ++j) {
            ids[j] = non_zeros[j - p];
            result = fmax(result, (n - j) * heights[ids[j]]);
        }
    }
    return result;
}
