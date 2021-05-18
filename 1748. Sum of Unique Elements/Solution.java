import java.util.HashMap;
import java.util.Map;

class Solution {
    public int sumOfUnique(int[] nums) {
        int res = 0;
        Map<Integer, Integer> map = new HashMap<>();
        for (int num : nums) {
            map.put(num, map.getOrDefault(num, 0) + 1);
        }
        for (Integer key : map.keySet()) {
            if (map.get(key) == 1) {
                res += key;
            }
        }
        return res;
    }
}
