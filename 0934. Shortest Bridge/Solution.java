import java.util.ArrayDeque;
import java.util.Queue;

class Solution {
    private final int[][] directions = new int[][]{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    private void dfs(int[][] grid, int r, int c, Queue<int[]> Q) {
        int m = grid.length, n = grid[0].length;
        if (r < 0 || r >= m || c < 0 || c >= n || grid[r][c] != 1) {
            return;
        }
        grid[r][c] = -1;
        Q.offer(new int[]{r, c});
        dfs(grid, r + 1, c, Q);
        dfs(grid, r - 1, c, Q);
        dfs(grid, r, c + 1, Q);
        dfs(grid, r, c - 1, Q);
    }

    public int shortestBridge(int[][] grid) {
        int m = grid.length, n = grid[0].length;
        Queue<int[]> queue = new ArrayDeque<>();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    dfs(grid, i, j, queue);
                    break;
                }
            }
            if (!queue.isEmpty()) {
                break;
            }
        }

        int steps = 0;
        while (!queue.isEmpty()) {
            int size = queue.size();
            while (size-- != 0) {
                int[] p = queue.remove();

                for (int[] direction : directions) {
                    int nr = p[0] + direction[0], nc = p[1] + direction[1];
                    if (nr < 0 || nr >= m || nc < 0 || nc >= n || grid[nr][nc] == -1) {
                        continue;
                    }
                    if (grid[nr][nc] == 1) {
                        return steps;
                    }
                    grid[nr][nc] = -1;
                    queue.offer(new int[]{nr, nc});
                }
            }
            ++steps;
        }
        return 0;
    }
}
