import java.util.HashMap;
import java.util.Map;

class Solution {
    public int maxEqualRowsAfterFlips(int[][] matrix) {
        int n = matrix[0].length, res = 0;
        Map<String, Integer> counter = new HashMap<>();
        for (int[] row : matrix) {
            char[] s = new char[n];
            for (int j = 0; j < n; j++) {
                s[j] = (char) (row[j] ^ row[0]);
            }
            int c = counter.merge(new String(s), 1, Integer::sum);
            res = Math.max(res, c);
        }
        return res;
    }
}
