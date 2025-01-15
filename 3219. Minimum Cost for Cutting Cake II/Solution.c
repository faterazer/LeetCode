#include <stdlib.h>

int cmp(const void* a, const void* b)
{
    return *(int*)b - *(int*)a;
}

long long minimumCost(int m, int n, int* horizontalCut, int horizontalCutSize, int* verticalCut, int verticalCutSize)
{
    qsort(horizontalCut, horizontalCutSize, sizeof(int), cmp);
    qsort(verticalCut, verticalCutSize, sizeof(int), cmp);
    long long ans = 0;
    int i = 0, j = 0;
    while (i < m - 1 || j < n - 1) {
        if (i == m - 1)
            ans += verticalCut[j++] * m;
        else if (j == n - 1)
            ans += horizontalCut[i++] * n;
        else if (horizontalCut[i] > verticalCut[j])
            ans += horizontalCut[i++] * (j + 1);
        else
            ans += verticalCut[j++] * (i + 1);
    }
    return ans;
}
