#include <vector>
using namespace std;

class Solution
{
public:
    void gameOfLife(vector<vector<int>> &board);
};

void Solution::gameOfLife(vector<vector<int>> &board)
{
    int m = board.size(), n = board[0].size();
    vector<pair<int, int>> directions = { {-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1} };
    // 增加状态 2，表示下一个更新为死细胞
    // 增加状态 -1， 表示下一个更新为活细胞
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int lives = 0;
            for (const pair<int, int> &d : directions) {
                int ni = i + d.first;
                int nj = j + d.second;
                if (ni < 0 || ni >= m || nj < 0 || nj >= n || board[ni][nj] <= 0)
                    continue;
                lives++;
            }
            if (board[i][j] && (lives < 2 || lives > 3))
                board[i][j] = 2;
            else if (!board[i][j] && lives == 3)
                board[i][j] = -1;
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j] == 2)
                board[i][j] = 0;
            else if (board[i][j] == -1)
                board[i][j] = 1;
        }
    }
}
