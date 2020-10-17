class Solution {
    public int[] sortedSquares(int[] A) {
        int[] ret = new int[A.length];
        int l = 0, r = A.length - 1, n = r;
        while (l <= r) {
            if (Math.abs(A[l]) > Math.abs(A[r]))
                ret[n--] = A[l] * A[l++];
            else
                ret[n--] = A[r] * A[r--];
        }
        return ret;
    }
}