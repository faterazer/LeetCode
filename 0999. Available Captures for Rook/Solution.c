int numRookCaptures(char **board, int boardSize, int *boardColSize)
{
    int x, y;
    for (x = 0; x < boardSize; x++) {
        for (y = 0; y < boardSize && board[x][y] != 'R'; y++)
            ;
        if (y < boardSize)
            break;
    }
    int res = 0;
    int dirs[][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    for (int i = 0; i < 4; i++) {
        for (int nx = x + dirs[i][0], ny = y + dirs[i][1]; nx >= 0 && nx < boardSize && ny >= 0 && ny < boardSize && board[nx][ny] != 'B'; nx += dirs[i][0], ny += dirs[i][1]) {
            if (board[nx][ny] == 'p') {
                res++;
                break;
            }
        }
    }
    return res;
}
