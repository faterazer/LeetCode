class Solution {
    public int oddCells(int n, int m, int[][] indices) {
        boolean[] r = new boolean[n], c = new boolean[m];
        for (int[] idx : indices) {
            r[idx[0]] ^= true;
            c[idx[1]] ^= true;
        }
        int res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                res += r[i] ^ c[j] ? 1 : 0;
            }
        }
        return res;
    }
}
