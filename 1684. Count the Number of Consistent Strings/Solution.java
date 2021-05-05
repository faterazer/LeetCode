import java.util.HashSet;
import java.util.Set;

class Solution {
    public int countConsistentStrings(String allowed, String[] words) {
        int res = words.length;
        Set<Character> set = new HashSet<>();
        for (int i = 0; i < allowed.length(); i++) {
            set.add(allowed.charAt(i));
        }
        for (String word : words) {
            for (int i = 0; i < word.length(); i++) {
                if (!set.contains(word.charAt(i))) {
                    res--;
                    break;
                }
            }
        }
        return res;
    }
}
