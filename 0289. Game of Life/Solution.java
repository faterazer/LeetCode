class Solution {
    public void gameOfLife(int[][] board) {
        // 增加状态 2，表示下一个更新为死细胞
        // 增加状态 -1， 表示下一个更新为活细胞
        int m = board.length, n = board[0].length;
        int[][] dirs = new int[][]{{1, 0}, {-1, 0}, {0, 1}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int lives = 0;
                for (int[] dir : dirs) {
                    int x = i + dir[0];
                    int y = j + dir[1];
                    if (x < 0 || x >= m || y < 0 || y >= n)
                        continue;
                    if (board[x][y] > 0)
                        lives++;
                }
                if (board[i][j] > 0 && (lives < 2 || lives > 3))
                    board[i][j] = 2;
                else if (board[i][j] == 0 && lives == 3)
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
}
