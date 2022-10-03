#include <math.h>

int minCost(char* colors, int* neededTime, int neededTimeSize)
{
    int max_cost = 0, res = 0;
    for (int i = 0; i < neededTimeSize; i++) {
        if (i > 0 && colors[i] != colors[i - 1])
            max_cost = 0;
        res += fmin(neededTime[i], max_cost);
        max_cost = fmax(max_cost, neededTime[i]);
    }
    return res;
}
