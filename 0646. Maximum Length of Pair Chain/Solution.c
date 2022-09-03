#include <stdlib.h>

int cmp(const void* a, const void* b)
{
    return (*(int**)a)[1] - (*(int**)b)[1];
}

int findLongestChain(int** pairs, int pairsSize, int* pairsColSize)
{
    qsort(pairs, pairsSize, sizeof(int*), cmp);
    int last = INT_MIN, res = 0;
    for (int i = 0; i < pairsSize; ++i) {
        if (pairs[i][0] > last) {
            last = pairs[i][1];
            ++res;
        }
    }
    return res;
}
