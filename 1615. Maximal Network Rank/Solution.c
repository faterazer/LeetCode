#include <math.h>
#include <string.h>

int maximalNetworkRank(int n, int** roads, int roadsSize, int* roadsColSize)
{
    int degree[n];
    memset(degree, 0, sizeof(degree));
    for (int i = 0; i < roadsSize; i++) {
        degree[roads[i][0]]++;
        degree[roads[i][1]]++;
    }

    int max1 = 0, max2 = 0;
    for (int i = 0; i < n; i++) {
        if (degree[i] > max1) {
            max2 = max1;
            max1 = degree[i];
        } else if (degree[i] > max2 && degree[i] < max1)
            max2 = degree[i];
    }

    int cnt1 = 0, cnt2 = 0;
    for (int i = 0; i < n; i++) {
        if (degree[i] == max1)
            cnt1++;
        if (degree[i] == max2)
            cnt2++;
    }

    if (cnt1 == 1) {
        int edge_cnt = 0;
        for (int i = 0; i < roadsSize; i++) {
            if (degree[roads[i][0]] == max1 && degree[roads[i][1]] == max2)
                edge_cnt++;
            if (degree[roads[i][0]] == max2 && degree[roads[i][1]] == max1)
                edge_cnt++;
        }
        return max1 + max2 - (edge_cnt == cnt2 ? 1 : 0);
    } else {
        int edge_cnt = 0, limit = cnt1 * (cnt1 - 1) / 2;
        for (int i = 0; i < roadsSize; i++) {
            if (degree[roads[i][0]] == max1 && degree[roads[i][1]] == max1)
                edge_cnt++;
        }
        return max1 * 2 - (edge_cnt == limit ? 1 : 0);
    }
}
