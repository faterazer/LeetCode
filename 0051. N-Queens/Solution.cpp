#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<string>> solveNQueens(int n)
    {
        vector<vector<string>> res;
        vector<string> board;
        helper(board, res, n, 0, 0, 0);
        return res;
    }

private:
    void helper(vector<string>& board, vector<vector<string>>& res, int n, int col_used, int dia1_used, int dia2_used)
    {
        if (board.size() == n) {
            res.emplace_back(board);
            return;
        }
        string line(n, '.');
        int pos = 1 << n;
        for (int i = 0; i < n; ++i) {
            pos >>= 1;
            if (col_used & pos || dia1_used & pos || dia2_used & pos)
                continue;
            line[i] = 'Q';
            board.emplace_back(line);
            helper(board, res, n, col_used | pos, (dia1_used | pos) << 1, (dia2_used | pos) >> 1);
            board.pop_back();
            line[i] = '.';
        }
    }
};
