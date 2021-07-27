import java.util.HashSet;
import java.util.Set;

class Solution {
    public int canBeTypedWords(String text, String brokenLetters) {
        Set<Character> set = new HashSet<>();
        for (int i = 0; i < brokenLetters.length(); i++) {
            set.add(brokenLetters.charAt(i));
        }

        int res = 0, hasBroken = 1;
        for (int i = 0; i < text.length(); i++) {
            if (text.charAt(i) == ' ') {
                res += hasBroken;
                hasBroken = 1;
            } else if (set.contains(text.charAt(i))) {
                hasBroken = 0;
            }
        }
        return res + hasBroken;
    }
}
