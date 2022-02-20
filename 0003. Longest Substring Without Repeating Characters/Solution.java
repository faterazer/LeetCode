import java.util.HashMap;
import java.util.Map;

class Solution {
    public int lengthOfLongestSubstring(String s) {
        Map<Character, Integer> dict = new HashMap<>();
        int beg = -1, res = 0;
        for (int i = 0; i < s.length(); i++) {
            if (dict.containsKey(s.charAt(i)) && dict.get(s.charAt(i)) > beg) {
                beg = dict.get(s.charAt(i));
            }
            dict.put(s.charAt(i), i);
            res = Math.max(res, i - beg);
        }
        return res;
    }
}
