import java.util.HashMap;
import java.util.Map;

class Solution {
    public int numPairsDivisibleBy60(int[] time) {
        int res = 0;
        Map<Integer, Integer> counter = new HashMap<>();
        for (int t : time) {
            res += counter.getOrDefault((60 - t % 60) % 60, 0);
            counter.put(t % 60, counter.getOrDefault(t % 60, 0) + 1);
        }
        return res;
    }
}
