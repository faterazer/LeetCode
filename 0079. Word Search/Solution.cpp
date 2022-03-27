#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word)
    {
        int m = board.size(), n = board[0].size();
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                if (board[i][j] == word[0] && exist(board, i, j, word, 0))
                    return true;
        return false;
    }

private:
    bool exist(vector<vector<char>>& board, int r, int c, const string& word, int idx)
    {
        if (idx == word.size())
            return true;
        int m = board.size(), n = board[0].size();
        if (r < 0 || r >= m || c < 0 || c >= n || board[r][c] != word[idx])
            return false;
        board[r][c] = '#';
        bool res = exist(board, r + 1, c, word, idx + 1) || exist(board, r - 1, c, word, idx + 1)
            || exist(board, r, c + 1, word, idx + 1) || exist(board, r, c - 1, word, idx + 1);
        board[r][c] = word[idx];
        return res;
    }
};
