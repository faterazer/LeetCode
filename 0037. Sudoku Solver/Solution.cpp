#include <vector>
using namespace std;

class Solution {
public:
    void solveSudoku(vector<vector<char>>& board)
    {
        vector<unsigned> rows(9, 0), cols(9, 0), boxes(9, 0);
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    int bit = 1 << (board[i][j] - '1');
                    rows[i] |= bit;
                    cols[j] |= bit;
                    boxes[i / 3 * 3 + j / 3] |= bit;
                }
            }
        }
        dfs(board, 0, 0, rows, cols, boxes);
    }

private:
    bool dfs(vector<vector<char>>& board, int i, int j, vector<unsigned>& rows, vector<unsigned>& cols, vector<unsigned>& boxes)
    {
        if (j == 9) {
            i++;
            j = 0;
        }
        while (i < 9 && board[i][j] != '.') {
            if (++j == 9) {
                i++;
                j = 0;
            }
        }

        if (i == 9)
            return true;

        for (int k = 0; k < 9; k++) {
            unsigned bit = 1 << k;
            if ((rows[i] & bit) || (cols[j] & bit) || (boxes[i / 3 * 3 + j / 3] & bit))
                continue;

            board[i][j] = '1' + k;
            rows[i] |= bit;
            cols[j] |= bit;
            boxes[i / 3 * 3 + j / 3] |= bit;

            if (dfs(board, i, j + 1, rows, cols, boxes))
                return true;

            boxes[i / 3 * 3 + j / 3] ^= bit;
            cols[j] ^= bit;
            rows[i] ^= bit;
            board[i][j] = '.';
        }
        return false;
    }
};
