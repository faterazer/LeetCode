class Solution {
    public int minimumRecolors(String blocks, int k) {
        int countW = 0, i = 0;
        for (; i < k; i++) {
            if (blocks.charAt(i) == 'W') {
                ++countW;
            }
        }

        int res = countW;
        for (; i < blocks.length(); i++) {
            if (blocks.charAt(i - k) == 'W') {
                --countW;
            }
            if (blocks.charAt(i) == 'W') {
                ++countW;
            }
            res = Math.min(res, countW);
        }
        return res;
    }
}
