#include <math.h>

int maximumWealth(int **accounts, int accountsSize, int *accountsColSize)
{
    int m = accountsSize, n = accountsColSize[0], res = 0;
    for (int i = 0; i < m; i++) {
        int temp = 0;
        for (int j = 0; j < n; j++)
            temp += accounts[i][j];
        res = fmax(res, temp);
    }
    return res;
}
