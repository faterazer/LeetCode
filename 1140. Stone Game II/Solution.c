#include <limits.h>
#include <math.h>

int stoneGameII(int* piles, int pilesSize)
{
    int suf_sum = 0, f[pilesSize][pilesSize / 2 + 2];
    for (int i = pilesSize - 1; i >= 0; i--) {
        suf_sum += piles[i];
        for (int m = 1; m <= i / 2 + 1; m++) {
            if (i + 2 * m >= pilesSize)
                f[i][m] = suf_sum;
            else {
                int min_val = INT_MAX;
                for (int x = 1; x <= 2 * m; x++)
                    min_val = fmin(min_val, f[i + x][(int)fmax(m, x)]);
                f[i][m] = suf_sum - min_val;
            }
        }
    }
    return f[0][1];
}
