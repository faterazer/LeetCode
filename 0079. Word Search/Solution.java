class Solution {
    private boolean dfs(char[][] board, int row, int col, String word, int idx) {
        if (idx == word.length()) {
            return true;
        }
        int m = board.length, n = board[0].length;
        if (row < 0 || row >= m || col < 0 || col >= n || board[row][col] != word.charAt(idx)) {
            return false;
        }
        board[row][col] = '#';
        boolean res = dfs(board, row + 1, col, word, idx + 1)
                || dfs(board, row - 1, col, word, idx + 1)
                || dfs(board, row, col + 1, word, idx + 1)
                || dfs(board, row, col - 1, word, idx + 1);
        board[row][col] = word.charAt(idx);
        return res;
    }

    public boolean exist(char[][] board, String word) {
        int m = board.length, n = board[0].length;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == word.charAt(0) && dfs(board, i, j, word, 0)) {
                    return true;
                }
            }
        }
        return false;
    }
}
