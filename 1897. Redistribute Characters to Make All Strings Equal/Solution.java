import java.util.HashMap;
import java.util.Map;

class Solution {
    public boolean makeEqual(String[] words) {
        Map<Character, Integer> map = new HashMap<>();
        for (String word : words) {
            for (int i = 0; i < word.length(); i++) {
                map.put(word.charAt(i), map.getOrDefault(word.charAt(i), 0) + 1);
            }
        }
        for (Integer value : map.values()) {
            if (value % words.length != 0) {
                return false;
            }
        }
        return true;
    }
}
