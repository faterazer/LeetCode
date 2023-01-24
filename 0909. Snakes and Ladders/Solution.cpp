#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board)
    {
        int n = board.size();
        vector<int> visited(n * n + 1, 0);
        queue<int> Q;
        Q.emplace(1);
        int steps = 0;
        while (!Q.empty()) {
            int len = Q.size();
            while (len--) {
                int pos = Q.front();
                Q.pop();

                for (int i = pos + 1; i <= min(pos + 6, n * n); i++) {
                    if (visited[i])
                        continue;
                    visited[i] = 1;
                    if (i == n * n)
                        return steps + 1;

                    int r = (i - 1) / n, c = (i - 1) % n;
                    if (r & 1)
                        c = n - 1 - c;
                    r = n - 1 - r;

                    if (board[r][c] != -1 && board[r][c] == n * n)
                        return steps + 1;

                    if (board[r][c] == -1)
                        Q.emplace(i);
                    else
                        Q.emplace(board[r][c]);
                }
            }
            ++steps;
        }
        return -1;
    }
};
