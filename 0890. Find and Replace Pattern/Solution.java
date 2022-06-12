import java.util.ArrayList;
import java.util.List;

class Solution {
    public List<String> findAndReplacePattern(String[] words, String pattern) {
        List<String> res = new ArrayList<>();
        for (String word : words) {
            boolean isMatch = true;
            for (int i = 0; i < word.length(); ++i) {
                if (word.indexOf(word.charAt(i)) != pattern.indexOf(pattern.charAt(i))) {
                    isMatch = false;
                    break;
                }
            }
            if (isMatch) {
                res.add(word);
            }
        }
        return res;
    }
}
