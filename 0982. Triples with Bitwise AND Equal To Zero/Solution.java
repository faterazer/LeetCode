import java.util.HashMap;
import java.util.Map;

class Solution {
    public int countTriplets(int[] nums) {
        Map<Integer, Integer> counter = new HashMap<>();
        for (int x : nums) {
            for (int y : nums) {
                counter.put(x & y, counter.getOrDefault(x & y, 0) + 1);
            }
        }

        int res = 0;
        for (int x : nums) {
            int m = x ^ 0xffff;
            for (int y = m; y != 0; y = (y - 1) & m) {
                res += counter.getOrDefault(y, 0);
            }
            res += counter.getOrDefault(0, 0);
        }
        return res;
    }
}
