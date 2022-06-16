import java.util.HashMap;
import java.util.Map;

class Solution {
    public int findPairs(int[] nums, int k) {
        Map<Integer, Integer> map = new HashMap<>();
        int res = 0;
        for (int num : nums) {
            map.put(num, map.getOrDefault(num, 0) + 1);
            if (k == 0) {
                res += map.get(num) == 2 ? 1 : 0;
            } else if (map.get(num) == 1) {
                if (map.containsKey(num - k)) {
                    ++res;
                }
                if (map.containsKey(num + k)) {
                    ++res;
                }
            }
        }
        return res;
    }
}

