#include <stdlib.h>

int cmp(const void* a, const void* b)
{
    return *(int*)a - *(int*)b;
}

int maxSatisfaction(int* satisfaction, int satisfactionSize)
{
    qsort(satisfaction, satisfactionSize, sizeof(int), cmp);
    int res = 0, total = 0;
    for (int i = satisfactionSize - 1; i >= 0 && satisfaction[i] > -total; i--) {
        total += satisfaction[i];
        res += total;
    }
    return res;
}
