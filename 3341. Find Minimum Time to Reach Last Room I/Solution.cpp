#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime)
    {
        int m = moveTime.size(), n = moveTime[0].size();
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;
        pq.emplace(0, 0, 0);
        vector<vector<int>> visited(m, vector<int>(n, 0));
        vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        while (!pq.empty()) {
            auto [cur_time, r, c] = pq.top();
            pq.pop();

            if (r == m - 1 && c == n - 1)
                return cur_time;
            
            if (visited[r][c])
                continue;
            visited[r][c] = 1;

            for (const auto& [dr, dc] : directions) {
                int nr = r + dr, nc = c + dc;
                if (nr < 0 || nr >= m || nc < 0 || nc >= n || visited[nr][nc])
                    continue;
                int nt = max(cur_time, moveTime[nr][nc]) + 1;
                if (nr == m - 1 && nc == n - 1)
                    return nt;
                else
                    pq.emplace(nt, nr, nc);
            }
        }
        return -1;
    }
};
