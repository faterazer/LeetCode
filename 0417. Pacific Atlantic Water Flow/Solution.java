import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

class Solution {
    private void dfs(int[][] heights, int r, int c, boolean[][] visited) {
        int m = heights.length, n = heights[0].length;
        if (r < 0 || r >= m || c < 0 || c >= n || visited[r][c]) {
            return;
        }
        visited[r][c] = true;
        if (r > 0 && heights[r][c] <= heights[r - 1][c]) {
            dfs(heights, r - 1, c, visited);
        }
        if (r < m - 1 && heights[r][c] <= heights[r + 1][c]) {
            dfs(heights, r + 1, c, visited);
        }
        if (c > 0 && heights[r][c] <= heights[r][c - 1]) {
            dfs(heights, r, c - 1, visited);
        }
        if (c < n - 1 && heights[r][c] <= heights[r][c + 1]) {
            dfs(heights, r, c + 1, visited);
        }
    }

    public List<List<Integer>> pacificAtlantic(int[][] heights) {
        int m = heights.length, n = heights[0].length;
        boolean[][] pacific = new boolean[m][n];
        boolean[][] atlantic = new boolean[m][n];

        for (int i = 0; i < m; i++) {
            dfs(heights, i, 0, pacific);
            dfs(heights, i, n - 1, atlantic);
        }
        for (int i = 0; i < n; i++) {
            dfs(heights, 0, i, pacific);
            dfs(heights, m - 1, i, atlantic);
        }

        List<List<Integer>> res = new ArrayList<>();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (pacific[i][j] && atlantic[i][j]) {
                    res.add(Arrays.asList(i, j));
                }
            }
        }
        return res;
    }
}
