class Solution {
    public int[][] transpose(int[][] A) {
        int m = A.length, n = A[0].length;
        int[][] ret = new int[n][m];
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                ret[j][i] = A[i][j];
        return ret;
    }
}
