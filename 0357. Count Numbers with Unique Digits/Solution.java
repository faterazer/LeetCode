ddclass Solution {
    public int countNumbersWithUniqueDigits(int n) {
        if (n == 0) {
            return 1;
        } else if (n == 1) {
            return 10;
        } else {
            int res = 10, temp = 9;
            for (int i = 2, j = 9; i <= n; ++i, --j) {
                res += temp * j;
                temp *= j;
            }
            return res;
        }
    }
}
