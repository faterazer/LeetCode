import java.util.HashMap;
import java.util.Map;

class Solution {
    public int rearrangeCharacters(String s, String target) {
        Map<Character, Integer> count = new HashMap<>();
        Map<Character, Integer> targetCount = new HashMap<>();
        for (int i = 0; i < s.length(); i++) {
            count.put(s.charAt(i), count.getOrDefault(s.charAt(i), 0) + 1);
        }
        for (int i = 0; i < target.length(); i++) {
            targetCount.put(target.charAt(i), targetCount.getOrDefault(target.charAt(i), 0) + 1);
        }
        int res = s.length();
        for (Map.Entry<Character, Integer> entry : targetCount.entrySet()) {
            res = Math.min(res, count.getOrDefault(entry.getKey(), 0) / entry.getValue());
        }
        return res;
    }
}
