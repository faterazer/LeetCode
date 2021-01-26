#include <math.h>

int numEquivDominoPairs(int **dominoes, int dominoesSize, int *dominoesColSize)
{
    int map[100] = {0}, res = 0;
    for (int i = 0; i < dominoesSize; i++) {
        int key = fmin(dominoes[i][0], dominoes[i][1]) * 10 + fmax(dominoes[i][0], dominoes[i][1]);
        res += map[key]++;
    }
    return res;
}
