class Solution {
    public int[] sumZero(int n) {
        int[] ret = new int[n];
        ret[0] = -n * (n - 1) / 2;
        for (int i = 1; i < n; i++) {
            ret[i] = i;
        }
        return ret;
    }
}
