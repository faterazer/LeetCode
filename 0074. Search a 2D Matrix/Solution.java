class Solution {
    public boolean searchMatrix_MK1(int[][] matrix, int target) {
        int m = matrix.length, n = matrix[0].length;
        int i = 0, j = n - 1;
        while (i < m && j >= 0) {
            if (matrix[i][0] > target) {
                return false;
            }
            if (matrix[i][j] < target) {
                i += 1;
            } else if (matrix[i][j] > target) {
                j -= 1;
            } else {
                return true;
            }
        }
        return false;
    }

    public boolean searchMatrix_MK2(int[][] matrix, int target) {
        int m = matrix.length, n = matrix[0].length;
        int left = 0, right = m * n - 1;
        while (left <= right) {
            int mid = left + ((right - left) >> 1);
            int val = matrix[mid / n][mid % n];
            if (val < target) {
                left = mid + 1;
            } else if (val > target) {
                right = mid - 1;
            } else {
                return true;
            }
        }
        return false;
    }
}
