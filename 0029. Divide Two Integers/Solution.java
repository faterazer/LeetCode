class Solution {
    public int divide(int dividend, int divisor) {
        if (divisor == 1) {
            return dividend;
        }
        if (dividend == divisor) {
            return 1;
        }
        if (dividend == 0 || divisor == Integer.MIN_VALUE) {
            return 0;
        }
        if (dividend == Integer.MIN_VALUE && divisor == -1) {
            return Integer.MAX_VALUE;
        }

        int sign = (dividend >= 0) == (divisor >= 0) ? 1 : -1;
        if (dividend == Integer.MIN_VALUE) {
            int res = (1 + divide(-(dividend + Math.abs(divisor)), Math.abs(divisor)));
            return sign > 0 ? res : -res;
        }

        int res = 0;
        dividend = Math.abs(dividend);
        divisor = Math.abs(divisor);
        while (dividend >= divisor) {
            int temp = divisor, cnt = 1;
            while (temp <= Integer.MAX_VALUE >> 1 && (temp << 1) <= dividend) {
                cnt <<= 1;
                temp <<= 1;
            }
            res += cnt;
            dividend -= temp;
        }
        return sign > 0 ? res : -res;
    }
}
