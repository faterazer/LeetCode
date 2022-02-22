class Solution {
    public int nthUglyNumber(int n) {
        int[] buff = new int[n];
        buff[0] = 1;
        int p2 = 0, p3 = 0, p5 = 0;
        for (int i = 1; i < n; i++) {
            buff[i] = Math.min(Math.min(buff[p2] * 2, buff[p3] * 3), buff[p5] * 5);
            if (buff[i] == buff[p2] * 2) {
                p2++;
            }
            if (buff[i] == buff[p3] * 3) {
                p3++;
            }
            if (buff[i] == buff[p5] * 5) {
                p5++;
            }
        }
        return buff[n - 1];
    }
}
