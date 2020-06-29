public class island_perimeter {
    public int islandPerimeter(int[][] grid) {
        int m = grid.length, n = grid[0].length;
        int islands = 0, neighbours = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j]) {
                    islands++;
                    if (i < m - 1 and grid[i + 1][j])
                        neighbours++;
                    if (j < n - 1 and grid[i][j + 1])
                        neighbours++;
                }
            }
        }
        return islands * 4 - neighbours * 2;
    }
}
