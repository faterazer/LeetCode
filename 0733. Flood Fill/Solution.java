class Solution {
    final int[][] dirs = { { 1, 0 }, { -1, 0 }, { 0, 1 }, { 0, -1 } };

    public int[][] floodFill(int[][] image, int sr, int sc, int newColor) {
        if (image[sr][sc] != newColor)
            dfsFill(image, sr, sc, newColor);
        return image;
    }

    private void dfsFill(int[][] image, int r, int c, int newColor) {
        int originColor = image[r][c];
        image[r][c] = newColor;
        for (int[] d : dirs) {
            int x = r + d[0];
            int y = c + d[1];
            if (x < 0 || x >= image.length || y < 0 || y >= image[0].length || image[x][y] != originColor)
                continue;
            dfsFill(image, x, y, newColor);
        }
    }
}
