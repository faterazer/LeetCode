#include <math.h>

int dfs(int i, int* manage, int* informTime)
{
    if (manage[i] != -1) {
        informTime[i] += dfs(manage[i], manage, informTime);
        manage[i] = -1;
    }
    return informTime[i];
}

int numOfMinutes(int n, int headID, int* manager, int managerSize, int* informTime, int informTimeSize)
{
    int res = 0;
    for (int i = 0; i < n; i++)
        res = fmax(res, dfs(i, manager, informTime));
    return res;
}
