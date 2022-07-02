#include <math.h>
#include <stdlib.h>

int cmp(const void* a, const void* b)
{
    return *(int*)a - *(int*)b;
}

int getMax(int n, int* cuts, int cutsSize)
{
    qsort(cuts, cutsSize, sizeof(int), cmp);
    int res = fmax(cuts[0], n - cuts[cutsSize - 1]);
    for (int i = 1; i < cutsSize; ++i)
        res = fmax(res, cuts[i] - cuts[i - 1]);
    return res;
}

int maxArea(int h, int w, int* horizontalCuts, int horizontalCutsSize, int* verticalCuts, int verticalCutsSize)
{
    const int P = 1000000007;
    return (long long)getMax(h, horizontalCuts, horizontalCutsSize) * getMax(w, verticalCuts, verticalCutsSize) % P;
}
