import java.util.Arrays;

class Solution {
    public int countDifferentSubsequenceGCDs(int[] nums) {
        int res = 0, maxVal = Arrays.stream(nums).max().orElse(0);
        boolean[] has = new boolean[maxVal + 1];
        for (int num : nums) {
            if (!has[num]) {
                has[num] = true;
                ++res;
            }
        }
        for (int i = 1; i * 3 <= maxVal; i++) {
            if (has[i]) {
                continue;
            }
            int g = 0;
            for (int j = 2 * i; j <= maxVal; j += i) {
                if (has[j]) {
                    g = gcd(g, j);
                }
            }
            if (g == i) {
                ++res;
            }
        }
        return res;
    }

    private int gcd(int a, int b) {
        if (b == 0) {
            return a;
        } else {
            return gcd(b, a % b);
        }
    }
}
