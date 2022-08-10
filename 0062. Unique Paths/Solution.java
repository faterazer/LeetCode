class Solution {
    public int uniquePaths(int m, int n) {
        if (m < n) {
            return uniquePaths(n, m);
        }
        long res = 1;
        for (int i = m, j = 1; j < n; i++, j++) {
            res = res * i / j;
        }
        return (int) res;
    }
}
