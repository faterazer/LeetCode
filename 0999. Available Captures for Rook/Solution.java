class Solution {
    public int numRookCaptures(char[][] board) {
        int x = -1, y = -1, size = board.length;
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                if (board[i][j] == 'R') {
                    x = i;
                    y = j;
                    break;
                }
            }
            if (x != -1) break;
        }
        int[][] dirs = new int[][]{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        int res = 0;
        for (int[] dir : dirs) {
            for (int nx = x + dir[0], ny = y + dir[1]; nx >= 0 && nx < size && ny >= 0 && ny < size && board[nx][ny] != 'B'; nx += dir[0], ny += dir[1]) {
                if (board[nx][ny] == 'p') {
                    res++;
                    break;
                }
            }
        }
        return res;
    }
}
