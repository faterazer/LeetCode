public class Solution {
    // you need to treat n as an unsigned value
    public int hammingWeight(int n) {
        int res = 0;
        for (; n != 0; n &= n - 1) {
            res++;
        }
        return res;
    }
}
