import java.util.HashMap;
import java.util.Map;

class Solution {
    public int numIdenticalPairs(int[] nums) {
        int res = 0;
        Map<Integer, Integer> counter = new HashMap<>();
        for (int x : nums) {
            int val = counter.getOrDefault(x, 0);
            res += val;
            counter.put(x, val + 1);
        }
        return res;
    }
}
