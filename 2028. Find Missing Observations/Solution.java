import java.util.Arrays;

class Solution {
    public int[] missingRolls(int[] rolls, int mean, int n) {
        int missingSum = mean * (rolls.length + n) - Arrays.stream(rolls).sum();
        if (missingSum < n || missingSum > 6 * n) {
            return new int[0];
        }
        int div = missingSum / n, mod = missingSum % n;
        int[] res = new int[n];
        Arrays.fill(res, div);
        for (int i = 0; i < mod; ++i) {
            res[i] += 1;
        }
        return res;
    }
}
