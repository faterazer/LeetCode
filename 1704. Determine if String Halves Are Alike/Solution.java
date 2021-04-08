import java.util.Set;

class Solution {
    public boolean halvesAreAlike(String s) {
        Set<Character> vowels = Set.of('a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U');
        int half = s.length() / 2, cnt = 0;
        for (int i = 0; i < half; i++) {
            if (vowels.contains(s.charAt(i))) {
                cnt++;
            }
        }
        for (int i = half; i < s.length(); i++) {
            if (vowels.contains(s.charAt(i)) && --cnt < 0) {
                return false;
            }
        }
        return cnt == 0;
    }
}
