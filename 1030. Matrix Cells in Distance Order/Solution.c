#include <stdlib.h>

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

// Sort
int R0, C0;

int cmp(const void *_a, const void *_b)
{
    int *a = *(int**)_a, *b = *(int**)_b;
    return abs(a[0] - R0) + abs(a[1] - C0) - abs(b[0] - R0) - abs(b[1] - C0);
}

int** allCellsDistOrder_MK1(int R, int C, int r0, int c0, int *returnSize, int **returnColumnSizes)
{
    *returnSize = R * C;
    int **ret = (int**)malloc(sizeof(int*) * *returnSize);
    *returnColumnSizes = (int*)malloc(sizeof(int) * *returnSize);
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            int idx = i * C + j;
            ret[idx] = (int*)malloc(sizeof(int) * 2);
            ret[idx][0] = i;
            ret[idx][1] = j;
            (*returnColumnSizes)[idx] = 2;
        }
    }
    R0 = r0;
    C0 = c0;
    qsort(ret, *returnSize, sizeof(int*), cmp);
    return ret;
}

// Bucket Sort
int** allCellsDistOrder_MK2(int R, int C, int r0, int c0, int *returnSize, int **returnColumnSizes)
{
    *returnSize = R * C;
    int **ret = (int**)malloc(sizeof(int*) * *returnSize);
    *returnColumnSizes = (int*)malloc(sizeof(int) * *returnSize);
    int idx = 0, dist = 0;
    int dirs[2] = {1, -1};
    while (idx < *returnSize) {
        for (int rowDist = 0; rowDist <= dist; rowDist++) {
            int colDist = dist - rowDist;
            for (int i = 0; i < 2; i++) {
                int r = r0 + rowDist * dirs[i];
                if (r < 0 || r >= R)
                    continue;
                for (int j = 0; j < 2; j++) {
                    int c = c0 + colDist * dirs[j];
                    if (c < 0 || c >= C)
                        continue;
                    ret[idx] = (int*)malloc(sizeof(int) * 2);
                    ret[idx][0] = r;
                    ret[idx][1] = c;
                    (*returnColumnSizes)[idx++] = 2;
                    if (colDist == 0)
                        break;
                }
                if (rowDist == 0)
                    break;
            }
        }
        dist++;
    }
    return ret;
}
