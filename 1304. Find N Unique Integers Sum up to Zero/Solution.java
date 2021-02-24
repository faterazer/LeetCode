class Solution {
    public int[] sumZero(int n) {
        int[] ret = new int[n];
        for (int i = 0; i < n - 1; i++) {
            ret[i] = i + 1;
        }
        ret[n - 1] = n * (1 - n) / 2;
        return ret;
    }
}
