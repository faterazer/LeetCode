class Solution {
    public int countDigitOne(int n) {
        int res = 0;
        int power = 1, tail = 0;
        for (; n != 0; n /= 10) {
            tail = n % 10 * power + tail;
            res += n / 10 * power + Math.min(Math.max(0, tail - power + 1), power);
            power *= 10;
        }
        return res;
    }
}
