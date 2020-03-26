#include <vector>
using namespace std;

class Solution
{
public:
    int numRookCaptures(vector<vector<char>> &board);
};

int Solution::numRookCaptures(vector<vector<char>> &board)
{
    int x, y, n = board.size();
    for (x = 0; x < n; x++)
    {
        for (y = 0; y < n && board[x][y] != 'R'; y++)
            ;
        if (y < n)
            break;
    }

    vector<pair<int, int>> direction = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int ret = 0;
    for (const pair<int, int> &d : direction) {
        for (int nx = x + d.first, ny = y + d.second; 0 <= nx && nx < n && 0 <= ny && ny < n && board[nx][ny] != 'B'; nx += d.first, ny += d.second) {
            if (board[nx][ny] == 'p') {
                ret++;
                break;
            }
        }
    }
    return ret;
}
