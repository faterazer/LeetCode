import java.util.HashMap;
import java.util.Map;

class Solution {
    public int maxOperations(int[] nums, int k) {
        Map<Integer, Integer> counter = new HashMap<>();
        for (int num : nums) {
            counter.put(num, counter.getOrDefault(num, 0) + 1);
        }
        int res = 0;
        for (Integer num : counter.keySet()) {
            int need = k - num;
            if (counter.containsKey(need)) {
                res += Math.min(counter.get(num), counter.get(need));
            }
        }
        return res / 2;
    }
}
