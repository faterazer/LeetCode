class Solution {
    public int minDeletionSize(String[] A) {
        int res = 0, m = A.length, n = A[0].length();
        for (int i = 0; i < n; i++) {
            for (int j = 1; j < m; j++) {
                if (A[j].charAt(i) < A[j - 1].charAt(i)) {
                    res++;
                    break;
                }
            }
        }
        return res;
    }
}
