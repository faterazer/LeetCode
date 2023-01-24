import java.util.LinkedList;
import java.util.Queue;

class Solution {
    public int snakesAndLadders(int[][] board) {
        int n = board.length;
        boolean[] visited = new boolean[n * n + 1];
        visited[1] = true;
        Queue<Integer> queue = new LinkedList<>();
        queue.offer(1);
        int steps = 0;
        while (!queue.isEmpty()) {
            int len = queue.size();
            while (len-- != 0) {
                Integer pos = queue.remove();
                for (int i = pos + 1; i <= Math.min(pos + 6, n * n); i++) {
                    if (visited[i]) {
                        continue;
                    }
                    visited[i] = true;
                    if (i == n * n) {
                        return steps + 1;
                    }

                    int r = (i - 1) / n, c = (i - 1) % n;
                    if (r % 2 == 1) {
                        c = n - 1 - c;
                    }
                    r = n - 1 - r;

                    if (board[r][c] != -1 && board[r][c] == n * n) {
                        return steps + 1;
                    }
                    if (board[r][c] == -1) {
                        queue.offer(i);
                    } else {
                        queue.offer(board[r][c]);
                    }
                }
            }
            ++steps;
        }
        return -1;
    }
}
