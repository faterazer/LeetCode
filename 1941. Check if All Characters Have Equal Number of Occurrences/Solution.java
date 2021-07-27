import java.util.HashMap;
import java.util.Map;

class Solution {
    public boolean areOccurrencesEqual(String s) {
        Map<Character, Integer> map = new HashMap<>();
        for (int i = 0; i < s.length(); i++) {
            map.put(s.charAt(i), map.getOrDefault(s.charAt(i), 0) + 1);
        }
        int last = 0;
        for (Integer value : map.values()) {
            if (value != 0) {
                if (last == 0) {
                    last = value;
                } else if (value != last) {
                    return false;
                }
            }
        }
        return true;
    }
}
