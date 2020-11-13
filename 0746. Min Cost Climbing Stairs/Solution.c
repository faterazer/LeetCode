#include <math.h>

int minCostClimbingStairs(int *cost, int costSize)
{
    int a = cost[0], b = cost[1], tmp;
    for (int i = 2; i < costSize; i++) {
        tmp = b;
        b = fmin(a, b) + cost[i];
        a = tmp;
    }
    return fmin(a, b);
}
