#include <vector>
using namespace std;

class Solution {
public:
    bool checkMove(vector<vector<char>>& board, int rMove, int cMove, char color)
    {
        int m = board.size(), n = board[0].size();
        for (auto& [dx, dy] : directions) {
            int x = rMove + dx, y = cMove + dy;
            if (x < 0 || x >= m || y < 0 || y >= n || board[x][y] != (color ^ 'B' ^ 'W'))
                continue;
            while (true) {
                x += dx;
                y += dy;
                if (x < 0 || x >= m || y < 0 || y >= n || board[x][y] == '.')
                    break;
                if (board[x][y] == color)
                    return true;
            }
        }
        return false;
    }

private:
    static constexpr int directions[8][2] { { 1, 0 }, { 1, 1 }, { 0, 1 }, { -1, 1 }, { -1, 0 }, { -1, -1 }, { 0, -1 }, { 1, -1 } };
};
