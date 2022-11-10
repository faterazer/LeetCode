#include <queue>
#include <string>
#include <unordered_set>
#include <vector>
using namespace std;

class State {
public:
    State(int _x, int _y, int _keys)
        : x(_x)
        , y(_y)
        , keys(_keys)
    {
    }

    int x, y, keys;
};

class Solution {
public:
    int shortestPathAllKeys(vector<string>& grid)
    {
        int m = grid.size(), n = grid[0].size();
        int x = 0, y = 0, all_keys = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '@') {
                    x = i;
                    y = j;
                } else if (islower(grid[i][j]))
                    all_keys |= 1 << (grid[i][j] - 'a');
            }
        }

        queue<State> Q;
        Q.emplace(State(x, y, 0));
        vector<vector<unordered_set<int>>> visited(m, vector<unordered_set<int>>(n));
        visited[x][y].emplace(0);
        int steps = 0;
        while (!Q.empty()) {
            int size = Q.size();
            while (size--) {
                State cur = Q.front();
                Q.pop();
                for (int i = 0; i < 4; i++) {
                    int nx = cur.x + dirs[i][0], ny = cur.y + dirs[i][1], keys = cur.keys;
                    if (nx < 0 || nx >= m || ny < 0 || ny >= n || grid[nx][ny] == '#' || (isupper(grid[nx][ny]) && !(keys & 1 << (grid[nx][ny] - 'A'))))
                        continue;
                    if (islower(grid[nx][ny]))
                        keys |= 1 << (grid[nx][ny] - 'a');
                    if (visited[nx][ny].count(keys))
                        continue;
                    if (keys == all_keys)
                        return steps + 1;
                    Q.emplace(State(nx, ny, keys));
                    visited[nx][ny].emplace(keys);
                }
            }
            ++steps;
        }
        return -1;
    }

private:
    static constexpr int dirs[4][2] { { 1, 0 }, { -1, 0 }, { 0, 1 }, { 0, -1 } };
};
