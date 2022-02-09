import java.util.HashMap;
import java.util.Map;

class Solution {
    public int countKDifference(int[] nums, int k) {
        Map<Integer, Integer> counter = new HashMap<>();
        int res = 0;
        for (int e : nums) {
            res += counter.getOrDefault(e - k, 0) + counter.getOrDefault(e + k, 0);
            counter.put(e, counter.getOrDefault(e, 0) + 1);
        }
        return res;
    }
}
