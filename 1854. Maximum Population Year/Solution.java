import java.util.HashMap;
import java.util.Map;

class Solution {
    public int maximumPopulation(int[][] logs) {
        int beg = Integer.MAX_VALUE, end = Integer.MIN_VALUE;
        int max = 0, temp = 0, res = 0;
        Map<Integer, Integer> map = new HashMap<>();
        for (int[] log : logs) {
            beg = Math.min(beg, log[0]);
            end = Math.max(end, log[0]);
            map.put(log[0], map.getOrDefault(log[0], 0) + 1);
            map.put(log[1], map.getOrDefault(log[1], 0) - 1);
        }
        for (int i = beg; i <= end; i++) {
            if (map.containsKey(i)) {
                temp += map.get(i);
                if (temp > max) {
                    max = temp;
                    res = i;
                }
            }
        }
        return res;
    }
}
