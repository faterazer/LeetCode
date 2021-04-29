class Solution {
    public int[] decrypt(int[] code, int k) {
        int[] res = new int[code.length];
        if (k == 0) {
            return res;
        }
        int beg = 1, end = k, sum = 0;
        if (k < 0) {
            beg = code.length + k;
            end = code.length - 1;
        }
        for (int i = beg; i <= end; i++)
            sum += code[i];
        for (int i = 0; i < res.length; i++) {
            res[i] = sum;
            sum -= code[(beg++) % code.length];
            sum += code[(++end) % code.length];
        }
        return res;
    }
}
