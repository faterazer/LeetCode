class Solution {
    /**
     * Time complexity: O(√c lgc).
     * Space complexity: O(1).
     */
    public boolean judgeSquareSum_MK1(int c) {
        int n = (int) Math.sqrt(c);
        for (int i = 0; i <= n; i++) {
            int j = (int) Math.sqrt(c - i * i);
            if (i * i + j * j == c)
                return true;
        }
        return false;
    }

    /**
     * Fermat Theorem: Any positive number n is expressible as a sum of two squares if
     * and only if the prime factorization of n, every prime of the form (4k+3) occurs
     * even number of times.
     * Time complexity: O(√c lgc).
     * Space complexity: O(1).
     */
    public boolean judgeSquareSum_MK2(int c) {
        for (int i = 2; i * i < c; i++) {
            if (c % i == 0) {
                int count = 0;
                while (c % i == 0) {
                    c /= i;
                    count++;
                }
                if (i % 4 == 3 && count % 2 != 0)
                    return false;
            }
        }
        return c % 4 != 3;
    }
}
