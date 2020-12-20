class Solution {
    public int binaryGap(int n) {
        int res = 0;
        for (int gap = -32; n != 0; n >>= 1, gap++) {
            if ((n & 1) == 1) {
                res = Math.max(res, gap);
                gap = 0;
            }
        }
        return res;
    }
}
