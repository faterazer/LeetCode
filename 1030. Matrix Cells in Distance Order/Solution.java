import java.util.*;

class Solution {
    // Sort
    public int[][] allCellsDistOrder_MK1(int R, int C, int r0, int c0) {
        int[][] ret = new int[R * C][];
        for (int i = 0; i < R; i++)
            for (int j = 0; j < C; j++)
                ret[i * C + j] = new int[]{i, j};
        Arrays.sort(ret, (a, b) -> Math.abs(a[0] - r0) + Math.abs(a[1] - c0) - Math.abs(b[0] - r0) - Math.abs(b[1] - c0));
        return ret;
    }

    // BFS
    public int[][] allCellsDistOrder_MK2(int R, int C, int r0, int c0) {
        boolean[][] visited = new boolean[R][C];
        visited[r0][c0] = true;
        Queue<int[]> queue = new LinkedList<>();
        queue.offer(new int[]{r0, c0});
        int[][] ret = new int[R * C][2];
        int idx = 0;
        int[][] dirs = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}};
        while (!queue.isEmpty()) {
            int[] cell = queue.poll();
            ret[idx++] = cell;
            for (int[] d : dirs) {
                int x = cell[0] + d[0];
                int y = cell[1] + d[1];
                if (x < 0 || x >= R || y < 0 || y >= C || visited[x][y])
                    continue;
                queue.offer(new int[]{x, y});
                visited[x][y] = true;
            }
        }
        return ret;
    }
}
