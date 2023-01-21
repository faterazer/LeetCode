import java.util.HashMap;
import java.util.Map;

class Solution {
    public int countNicePairs(int[] nums) {
        int res = 0, MOD = (int) (1e9 + 7);
        Map<Integer, Integer> counter = new HashMap<>();
        for (int num : nums) {
            int sub = num - rev(num);
            int c = counter.getOrDefault(sub, 0);
            res = (res + c) % MOD;
            counter.put(sub, c + 1);
        }
        return res;
    }

    private int rev(int x) {
        int res = 0;
        while (x != 0) {
            res = res * 10 + x % 10;
            x /= 10;
        }
        return res;
    }
}
