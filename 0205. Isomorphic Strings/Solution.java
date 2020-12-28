import java.util.HashMap;
import java.util.Map;

class Solution {
    public boolean isIsomorphic(String s, String t) {
        Map<Character, Integer> s2i = new HashMap<>();
        Map<Character, Integer> t2i = new HashMap<>();
        for (int i = 0; i < s.length(); i++) {
            if (!s2i.getOrDefault(s.charAt(i), -1).equals(t2i.getOrDefault(t.charAt(i), -1))) {
                return false;
            }
            s2i.put(s.charAt(i), i);
            t2i.put(t.charAt(i), i);
        }
        return true;
    }
}
