class Solution {
    public int[][] imageSmoother(int[][] M) {
        int m = M.length, n = M[0].length;
        int[][] dirs = {{-1, 1}, {0, 1}, {1, 1}, {-1, 0}, {1, 0}, {-1, -1}, {0, -1}, {1, -1}};
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int sum = M[i][j], count = 1;
                for (int[] d : dirs) {
                    int ni = i + d[0];
                    int nj = j + d[1];
                    if (ni < 0 || ni >= m || nj < 0 || nj >= n)
                        continue;
                    sum += (M[ni][nj] & 0xFF);
                    count += 1;
                }
                M[i][j] |= (sum / count) << 8;
            }
        }
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                M[i][j] >>= 8;
        return M;
    }
}
