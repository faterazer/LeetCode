#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms)
    {
        int m = rooms.size(), n = rooms[0].size();
        queue<pair<int, int>> Q;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (rooms[i][j] == 0)
                    Q.emplace(i, j);

        vector<vector<int>> directions { { 0, 1 }, { 0, -1 }, { 1, 0 }, { -1, 0 } };
        while (!Q.empty()) {
            int size = Q.size();
            for (int i = 0; i < size; i++) {
                int r = Q.front().first, c = Q.front().second;
                Q.pop();

                for (const vector<int>& d : directions) {
                    int nr = r + d[0], nc = c + d[1];
                    if (nr < 0 || nr >= m || nc < 0 || nc >= n || rooms[nr][nc] != 2147483647)
                        continue;
                    rooms[nr][nc] = rooms[r][c] + 1;
                    Q.emplace(nr, nc);
                }
            }
        }
    }
};
