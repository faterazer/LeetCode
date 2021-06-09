#include <limits.h>
#include <math.h>
#include <memory.h>
#include <stdlib.h>

int maximumPopulation(int **logs, int logsSize, int *logsColSize)
{
    int beg = INT_MAX, end = INT_MIN;
    int mx = 0, tmp = 0, res = 0;
    for (int i = 0; i < logsSize; i++) {
        beg = fmin(beg, logs[i][0]);
        end = fmax(end, logs[i][1]);
    }

    int *growth_rate = (int*)malloc(sizeof(int) * (end - beg + 1));
    memset(growth_rate, 0, sizeof(int) * (end - beg + 1));
    for (int i = 0; i < logsSize; i++) {
        growth_rate[logs[i][0] - beg]++;
        growth_rate[logs[i][1] - beg]--;
    }
    for (int i = beg; i <= end; i++) {
        tmp += growth_rate[i - beg];
        if (tmp > mx) {
            mx = tmp;
            res = i;
        }
    }
    return res;
}
