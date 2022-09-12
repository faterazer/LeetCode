#include <math.h>
#include <stdlib.h>

int cmp(const void* a, const void* b)
{
    return *(int*)a - *(int*)b;
}

int bagOfTokensScore(int* tokens, int tokensSize, int power)
{
    qsort(tokens, tokensSize, sizeof(int), cmp);
    int res = 0, score = 0, i = 0, j = tokensSize - 1;
    while (i <= j) {
        if (power >= tokens[i]) {
            power -= tokens[i++];
            res = fmax(res, ++score);
        } else if (score > 0) {
            --score;
            power += tokens[j--];
        } else
            break;
    }
    return res;
}
