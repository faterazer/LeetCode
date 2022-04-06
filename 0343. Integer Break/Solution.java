class Solution {
    public int integerBreak(int n) {
        if (n < 4) {
            return n - 1;
        }
        int div = n / 3, mod = n % 3;
        if (mod == 0) {
            return (int) Math.pow(3, div);
        } else if (mod == 1) {
            return (int) Math.pow(3, div - 1) * 4;
        } else {
            return (int) Math.pow(3, div) * 2;
        }
    }
}
