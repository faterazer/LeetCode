import java.util.HashMap;
import java.util.Map;

class Solution {
    public boolean wordPattern(String pattern, String str) {
        Map<Character, Integer> p2i = new HashMap<>();
        Map<String, Integer> s2i = new HashMap<>();
        int i = 0, n = pattern.length();
        for (String word : str.split(" ")) {
            if (i == n || !p2i.getOrDefault(pattern.charAt(i), -1).equals(s2i.getOrDefault(word, -1)))
                return false;
            p2i.put(pattern.charAt(i), i);
            s2i.put(word, i);
            i += 1;
        }
        return i == n;
    }
}
