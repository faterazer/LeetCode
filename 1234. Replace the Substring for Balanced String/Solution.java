import java.util.HashMap;
import java.util.Map;

class Solution {
    public int balancedString(String s) {
        Map<Character, Integer> count = new HashMap<>();
        int n = s.length(), res = n, limit = n / 4, i = 0;
        for (int j = 0; j < n; j++) {
            count.put(s.charAt(j), count.getOrDefault(s.charAt(j), 0) + 1);
        }
        if (count.getOrDefault('Q', 0) == limit && count.getOrDefault('W', 0) == limit && count.getOrDefault('R', 0) == limit) {
            return 0;
        }
        for (int j = 0; j < n; j++) {
            count.put(s.charAt(j), count.get(s.charAt(j)) - 1);
            while (count.getOrDefault('Q', 0) <= limit && count.getOrDefault('W', 0) <= limit && count.getOrDefault('E', 0) <= limit && count.getOrDefault('R', 0) <= limit) {
                res = Math.min(res, j - i + 1);
                count.put(s.charAt(i), count.getOrDefault(s.charAt(i), 0) + 1);
                ++i;
            }
        }
        return res;
    }
}
