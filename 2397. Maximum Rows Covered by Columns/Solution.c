#include <math.h>
#include <string.h>

int maximumRows(int** matrix, int matrixSize, int* matrixColSize, int numSelect)
{
    int m = matrixSize, n = matrixColSize[0];
    unsigned masks[m];
    memset(masks, 0, sizeof(masks));
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            masks[i] |= matrix[i][j] << j;

    int res = 0;
    unsigned x = (1 << numSelect) - 1;
    while (x < (1 << n)) {
        int covered_rows = 0;
        for (int i = 0; i < m; i++)
            if ((masks[i] & x) == masks[i])
                covered_rows++;
        res = fmax(res, covered_rows);

        unsigned low_bit = x & -x;
        x = (x + low_bit) | ((x ^ (x + low_bit)) / low_bit >> 2);
    }
    return res;
}
