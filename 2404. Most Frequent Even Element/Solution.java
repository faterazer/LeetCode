import java.util.HashMap;
import java.util.Map;

class Solution {
    public int mostFrequentEven(int[] nums) {
        Map<Integer, Integer> counter = new HashMap<>();
        int res = -1;
        for (int x : nums) {
            if (x % 2 == 1) {
                continue;
            }
            int c = counter.merge(x, 1, Integer::sum);
            if (c > counter.getOrDefault(res, 0) || c == counter.get(res) && x < res) {
                res = x;
            }
        }
        return res;
    }
}
