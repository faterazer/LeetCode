class Solution {
    public int hammingDistance_MK1(int x, int y) {
        return Integer.bitCount(x ^ y);
    }

    public int hammingDistance_MK2(int x, int y) {
        int res = 0;
        for (x ^= y; x != 0; x &= x - 1) {
            res++;
        }
        return res;
    }
}
