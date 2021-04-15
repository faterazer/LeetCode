class Solution {
    public int numSpecial(int[][] mat) {
        int m = mat.length, n = mat[0].length, res = 0;
        int[] rows_sum = new int[m];
        int[] cols_sum = new int[n];
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 1) {
                    rows_sum[i]++;
                    cols_sum[j]++;
                }
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 1 && rows_sum[i] == 1 && cols_sum[j] == 1) {
                    res++;
                }
            }
        }
        return res;
    }
}
