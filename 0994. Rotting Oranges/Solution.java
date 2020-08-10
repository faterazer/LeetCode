import java.util.LinkedList;
import java.util.Queue;

class Solution {
    public int orangesRotting(int[][] grid) {
        int m = grid.length, n = grid[0].length;
        Queue<int[]> queue = new LinkedList<>();
        int freshOranges = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1)
                    freshOranges++;
                else if (grid[i][j] == 2)
                    queue.offer(new int[]{i, j});
            }
        }

        int[][] direction = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        int minutes = 0;
        while (!queue.isEmpty() && freshOranges > 0) {
            minutes++;
            int size = queue.size();
            while (size-- > 0) {
                int[] rottenOrange = queue.poll();
                for (int[] d : direction) {
                    int x = rottenOrange[0] + d[0];
                    int y = rottenOrange[1] + d[1];
                    if (x < 0 || x >= m || y < 0 || y >= n || grid[x][y] != 1)
                        continue;
                    queue.offer(new int[]{x, y});
                    grid[x][y] = 2;
                    freshOranges--;
                }
            }
        }
        return freshOranges == 0 ? minutes : -1;
    }
}
