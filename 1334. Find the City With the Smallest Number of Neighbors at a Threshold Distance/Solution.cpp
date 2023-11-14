#include <vector>
using namespace std;

class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold)
    {
        vector<vector<int>> graph(n, vector<int>(n, INT_MAX / 2));
        for (const vector<int>& edge : edges) {
            graph[edge[0]][edge[1]] = edge[2];
            graph[edge[1]][edge[0]] = edge[2];
        }

        for (int k = 0; k < n; k++) {
            graph[k][k] = 0;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (i == j)
                        continue;
                    graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
                }
            }
        }

        int res = -1, min_cnt = INT_MAX;
        for (int i = 0; i < n; i++) {
            int cnt = 0;
            for (int j = 0; j < n; j++)
                if (i != j && graph[i][j] <= distanceThreshold)
                    cnt++;
            if (cnt <= min_cnt) {
                min_cnt = cnt;
                res = i;
            }
        }
        return res;
    }
};
