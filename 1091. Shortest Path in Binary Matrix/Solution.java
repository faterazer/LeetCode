import java.util.ArrayDeque;
import java.util.Queue;

class Solution {
    public int shortestPathBinaryMatrix(int[][] grid) {
        int m = grid.length, n = grid[0].length;
        if (grid[0][0] != 0 || grid[m - 1][n - 1] != 0) {
            return -1;
        }
        if (m == 1 && n == 1) {
            return 1;
        }
        boolean[][] visited = new boolean[m][n];
        visited[0][0] = true;
        int[][] directions = new int[][]{{-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}};
        Queue<int[]> frontier = new ArrayDeque<>();
        frontier.add(new int[]{0, 0});
        int steps = 0;
        while (!frontier.isEmpty()) {
            ++steps;
            int size = frontier.size();
            for (int i = 0; i < size; i++) {
                int[] position = frontier.remove();
                for (int[] direction : directions) {
                    int nr = position[0] + direction[0], nc = position[1] + direction[1];
                    if (nr < 0 || nr >= m || nc < 0 || nc >= n || grid[nr][nc] != 0 || visited[nr][nc]) {
                        continue;
                    }
                    if (nr == m - 1 && nc == n - 1) {
                        return steps + 1;
                    }
                    visited[nr][nc] = true;
                    frontier.add(new int[]{nr, nc});
                }
            }
        }
        return -1;
    }
}
