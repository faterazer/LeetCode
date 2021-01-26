import java.util.HashMap;
import java.util.Map;

class Solution {
    public int numEquivDominoPairs(int[][] dominoes) {
        Map<Integer, Integer> map = new HashMap<>();
        int res = 0;
        for (int[] dominoe : dominoes) {
            int key = Math.min(dominoe[0], dominoe[1]) * 10 + Math.max(dominoe[0], dominoe[1]);
            map.put(key, map.getOrDefault(key, 0) + 1);
            res += map.get(key) - 1;
        }
        return res;
    }
}
