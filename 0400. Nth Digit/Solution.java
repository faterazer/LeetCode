class Solution {
    public int findNthDigit(int n) {
        int digits = 1, nums = 9, base = 0;
        while (n / digits > nums) {
            n -= digits * nums;
            digits += 1;
            nums *= 10;
            base = base * 10 + 9;
        }
        int res = base + n / digits;
        if (n % digits != 0) {
            res += 1;
        }
        return Integer.toString(res).charAt((n % digits - 1 + digits) % digits) - '0';
    }
}
