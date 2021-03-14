import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

class Solution {
    public List<String> stringMatching(String[] words) {
        Arrays.sort(words, (a, b) -> (b.length() - a.length()));
        List<String> res = new ArrayList<>();
        for (int i = 1; i < words.length; i++) {
            for (int j = 0; j < i; j++) {
                if (words[j].contains(words[i])) {
                    res.add(words[i]);
                    break;
                }
            }
        }
        return res;
    }
}
