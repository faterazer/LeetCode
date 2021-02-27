class Solution {
    public int[] getNoZeroIntegers(int n) {
        int[] res = new int[2];
        int digit;
        for (int power = 1; n > 0; n /= 10, power *= 10) {
            if (n % 10 > 2 || n < 10) {
                digit = n % 10;
            } else {
                digit = 10 + n % 10;
                n -= 10;
            }
            res[0] += digit / 2 * power;
            res[1] += (digit + 1) / 2 * power;
        }
        return res;
    }
}
