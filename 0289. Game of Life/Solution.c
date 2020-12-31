void gameOfLife(int **board, int boardSize, int *boardColSize)
{
    // 增加状态 2，表示下一个更新为死细胞
    // 增加状态 -1， 表示下一个更新为活细胞
    int m = boardSize, n = boardColSize[0];
    int dirs[8][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int cnt = 0;
            for (int k = 0; k < 8; k++) {
                int x = i + dirs[k][0];
                int y = j + dirs[k][1];
                if (x < 0 || x >= m || y < 0 || y >= n)
                    continue;
                cnt += board[x][y] > 0;
            }
            if (board[i][j] && (cnt < 2 || cnt > 3))
                board[i][j] = 2;
            else if (!board[i][j] && cnt == 3)
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
