import java.util.ArrayList;
import java.util.List;

class Solution {
    public List<Integer> spiralOrder(int[][] matrix) {
        List<Integer> res = new ArrayList<>();
        if (matrix == null || matrix.length == 0 || matrix[0].length == 0) {
            return res;
        }
        int m = matrix.length, n = matrix[0].length;
        int rowBegin = 0, rowEnd = m - 1, colBegin = 0, colEnd = n - 1;
        while (rowBegin <= rowEnd && colBegin <= colEnd) {
            for (int i = colBegin; i <= colEnd; ++i) {
                res.add(matrix[rowBegin][i]);
            }
            for (int i = rowBegin + 1; i <= rowEnd; ++i) {
                res.add(matrix[i][colEnd]);
            }
            for (int i = colEnd - 1; i >= colBegin && rowBegin < rowEnd; --i) {
                res.add(matrix[rowEnd][i]);
            }
            for (int i = rowEnd - 1; i > rowBegin && colBegin < colEnd; --i) {
                res.add(matrix[i][colBegin]);
            }

            rowBegin += 1;
            rowEnd -= 1;
            colBegin += 1;
            colEnd -= 1;
        }
        return res;
    }
}
