#include <stdbool.h>

bool dfs(char** board, int m, int n, int r, int c, char* word, int idx)
{
    if (!word[idx])
        return true;
    if (r < 0 || r >= m || c < 0 || c >= n || board[r][c] != word[idx])
        return false;
    board[r][c] = '#';
    bool res = dfs(board, m, n, r + 1, c, word, idx + 1)
        || dfs(board, m, n, r - 1, c, word, idx + 1)
        || dfs(board, m, n, r, c + 1, word, idx + 1)
        || dfs(board, m, n, r, c - 1, word, idx + 1);
    board[r][c] = word[idx];
    return res;
}

bool exist(char** board, int boardSize, int* boardColSize, char* word)
{
    int m = boardSize, n = boardColSize[0];
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
            if (board[i][j] == word[0] && dfs(board, m, n, i, j, word, 0))
                return true;
    return false;
}
