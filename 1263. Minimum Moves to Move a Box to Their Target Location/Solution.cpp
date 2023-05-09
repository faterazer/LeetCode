#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

struct State {
    State() = default;

    State(int _br, int _bc, int _sr, int _sc)
        : br(_br)
        , bc(_bc)
        , sr(_sr)
        , sc(_sc)
    {
    }

    int br, bc, sr, sc;
};

class Solution {
public:
    int minPushBox(vector<vector<char>>& grid)
    {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dirs { { 1, 0 }, { -1, 0 }, { 0, 1 }, { 0, -1 } };
        State start;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 'B') {
                    start.br = i;
                    start.bc = j;
                } else if (grid[i][j] == 'S') {
                    start.sr = i;
                    start.sc = j;
                }
            }
        }

        queue<State> Q;
        Q.emplace(start);
        bool seen[m][n][m][n];
        fill_n(&seen[0][0][0][0], m * n * m * n, false);
        seen[start.br][start.bc][start.sr][start.sc] = true;
        int pushes = 0;
        while (!Q.empty()) {
            queue<State> next_Q;
            while (!Q.empty()) {
                State state = Q.front();
                Q.pop();

                if (grid[state.br][state.bc] == 'T')
                    return pushes;

                for (const vector<int>& d : dirs) {
                    int sr = state.sr + d[0], sc = state.sc + d[1];
                    if (sr < 0 || sr >= m || sc < 0 || sc >= n || grid[sr][sc] == '#')
                        continue;
                    if (sr == state.br && sc == state.bc) {
                        int br = state.br + d[0], bc = state.bc + d[1];
                        if (br < 0 || br >= m || bc < 0 || bc >= n || grid[br][bc] == '#' || seen[br][bc][sr][sc])
                            continue;
                        seen[br][bc][sr][sc] = true;
                        next_Q.emplace(State(br, bc, sr, sc));
                    } else if (!seen[state.br][state.bc][sr][sc]) {
                        seen[state.br][state.bc][sr][sc] = true;
                        Q.emplace(State(state.br, state.bc, sr, sc));
                    }
                }
            }
            Q.swap(next_Q);
            pushes++;
        }
        return -1;
    }
};
