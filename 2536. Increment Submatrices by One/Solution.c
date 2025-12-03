/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
#include <stdlib.h>

int** rangeAddQueries(int n, int** queries, int queriesSize, int* queriesColSize, int* returnSize, int** returnColumnSizes)
{
    *returnSize = n;
    *returnColumnSizes = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; ++i)
        (*returnColumnSizes)[i] = n;

    int** diff = (int**)malloc((n + 2) * sizeof(int*));
    int* diff_data_block = (int*)calloc((n + 2) * (n + 2), sizeof(int));
    for (int i = 0; i < n + 2; ++i)
        diff[i] = diff_data_block + i * (n + 2);
    for (int i = 0; i < queriesSize; ++i) {
        int r1 = queries[i][0], c1 = queries[i][1], r2 = queries[i][2], c2 = queries[i][3];
        ++diff[r1 + 1][c1 + 1];
        --diff[r1 + 1][c2 + 2];
        --diff[r2 + 2][c1 + 1];
        ++diff[r2 + 2][c2 + 2];
    }

    int** result = (int**)malloc(n * sizeof(int*));
    int* result_data_block = (int*)malloc(n * n * sizeof(int));
    for (int i = 0; i < n; ++i) {
        result[i] = result_data_block + i * n;
        for (int j = 0; j < n; ++j) {
            diff[i + 1][j + 1] += diff[i + 1][j] + diff[i][j + 1] - diff[i][j];
            result[i][j] = diff[i + 1][j + 1];
        }
    }
    free(diff_data_block);
    free(diff);
    return result;
}
