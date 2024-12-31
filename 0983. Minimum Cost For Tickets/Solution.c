#include <math.h>
#include <string.h>

int mincostTickets(int* days, int daysSize, int* costs, int costsSize)
{
    int f[daysSize + 1];
    memset(f, 0, sizeof(f));
    int j = 0, k = 0;
    for (int i = 0; i < daysSize; ++i) {
        f[i + 1] = f[i] + costs[0];
        while (days[i] - days[j] >= 7)
            ++j;
        f[i + 1] = fmin(f[i + 1], f[j] + costs[1]);
        while (days[i] - days[k] >= 30)
            ++k;
        f[i + 1] = fmin(f[i + 1], f[k] + costs[2]);
    }
    return f[daysSize];
}
