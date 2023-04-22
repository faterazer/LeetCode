import java.util.Arrays;

class Solution {
    public int longestArithSeqLength(int[] nums) {
        int min = Arrays.stream(nums).min().orElse(0);
        int max = Arrays.stream(nums).max().orElse(0);
        int diff = max - min, res = 1;
        for (int d = -diff; d <= diff; d++) {
            int[] f = new int[max + 1];
            for (int x : nums) {
                int prev = x + d;
                if (prev >= min && prev <= max) {
                    f[x] = Math.max(f[x], f[prev] + 1);
                    res = Math.max(res, f[x]);
                }
                f[x] = Math.max(f[x], 1);
            }
        }
        return res;
    }
}
