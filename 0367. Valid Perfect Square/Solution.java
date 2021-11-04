class Solution {
    public boolean isPerfectSquare(int num) {
        int root = sqrtByNewton(num);
        return num % root == 0 && num / root == root;
    }

    private int sqrtByLinearSearch(int n) {
        int i = 1;
        while (i < n / i) {
            i++;
        }
        return i;
    }

    private int sqrtByBinarySearch(int n) {
        if (n == 1) {
            return n;
        }
        int l = 2, r = n / 2, m;
        while (l < r) {
            m = l + ((r - l) >> 1);
            if (n / m == m) {
                return m;
            } else if (m < n / m) {
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        return r;
    }

    private int sqrtByNewton(int n) {
         int r = n / 2 + 1;
         while (n / r != r) {
             r = (r + n / r) / 2;
         }
         return r;
    }
}
