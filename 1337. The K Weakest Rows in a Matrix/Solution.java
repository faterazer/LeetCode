import java.util.Arrays;

class Solution {
    public int[] kWeakestRows(int[][] mat, int k) {
        int[][] buff = new int[mat.length][];
        for (int i = 0; i < mat.length; i++) {
            buff[i] = new int[]{countOnes(mat[i]), i};
        }
        Arrays.sort(buff, (int[] a, int[] b) -> a[0] != b[0] ? a[0] - b[0] : a[1] - b[1]);
        int[] ret = new int[k];
        for (int i = 0; i < k; i++) {
            ret[i] = buff[i][1];
        }
        return ret;
    }

    private int countOnes(int[] row) {
        int l = 0, r = row.length;
        while (l < r) {
            int m = l + ((r - l) >> 1);
            if (row[m] == 1) {
                l = m + 1;
            } else {
                r = m;
            }
        }
        return l;
    }
}
