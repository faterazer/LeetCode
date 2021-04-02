class Solution {
    public int xorOperation_MK1(int n, int start) {
        int res = 0;
        for (int i = 0; i < n; i++, start += 2) {
            res ^= start;
        }
        return res;
    }

    public int xorOperation_MK2(int n, int start) {
        int res = helper(n, start >> 1) << 1;
        if ((n & start & 1) == 1) {
            res |= 1;
        }
        return res;
    }

    private int helper(int n, int start) {
        if (start % 2 == 1) {
            return (start - 1) ^ helper(n + 1, start - 1);
        }
        if (n % 2 == 0) {
            return (n / 2) & 1;
        } else {
            return (n / 2 ) & 1 ^ (start + n - 1);
        }
    }
}
