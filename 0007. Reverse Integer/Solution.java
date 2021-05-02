class Solution {
    public int reverse(int x) {
        int res = 0;
        for (; x != 0; x /= 10)  {
            if (res < Integer.MIN_VALUE / 10 || res > Integer.MAX_VALUE / 10) {
                return 0;
            }
            res = res * 10 + x % 10;
        }
        return res;
    }
}
