import java.util.HashMap;
import java.util.Map;

class Solution {
    public int findLucky(int[] arr) {
        Map<Integer, Integer> map = new HashMap<>();
        for (int x : arr) {
            map.put(x, map.getOrDefault(x, 0) + 1);
        }
        int res = -1;
        for (Integer x : map.keySet()) {
            if (x == map.get(x)) {
                res = Math.max(x, res);
            }
        }
        return res;
    }
}
