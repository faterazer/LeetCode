#include <algorithm>
#include <map>
#include <queue>
#include <vector>
using namespace std;

class Solution
{
public:
    // BFS
    vector<vector<int>> allCellsDistOrder_MK1(int R, int C, int r0, int c0)
    {
        vector<vector<int>> visited(R, vector<int>(C, 0));
        visited[r0][c0] = 1;
        queue<vector<int>> Q;
        Q.push({r0, c0});
        vector<pair<int, int>> dirs{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        vector<vector<int>> ret;
        while (!Q.empty()) {
            vector<int> pos = Q.front();
            Q.pop();
            ret.emplace_back(pos);
            for (const pair<int, int> &d : dirs) {
                int x = pos[0] + d.first;
                int y = pos[1] + d.second;
                if (x < 0 || x >= R || y < 0 || y >= C || visited[x][y])
                    continue;
                Q.push({x, y});
                visited[x][y] = 1;
            }
        }
        return ret;
    }

    // Sort
    vector<vector<int>> allCellsDistOrder_MK2(int R, int C, int r0, int c0)
    {
        vector<vector<int>> ret;
        for (int i = 0; i < R; i++)
            for (int j = 0; j < C; j++)
                ret.push_back({i, j});
        sort(ret.begin(), ret.end(), [&](const vector<int> &a, const vector<int> &b) {
            return abs(a[0] - r0) + abs(a[1] - c0) < abs(b[0] - r0) + abs(b[1] - c0);
        });
        return ret;
    }

    // Bucket Sort
    vector<vector<int>> allCellsDistOrder_MK3(int R, int C, int r0, int c0)
    {
        map<int, vector<vector<int>>> buckets;
        for (int i = 0; i < R; i++)
            for (int j = 0; j < C; j++)
                buckets[abs(i - r0) + abs(j - c0)].push_back({i, j});
        vector<vector<int>> ret;
        for (auto it = buckets.begin(); it != buckets.end(); it++)
            ret.insert(ret.end(), it->second.begin(), it->second.end());
        return ret;
    }
};
