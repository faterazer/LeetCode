import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

class Solution {
    private boolean valid(Map<String, Integer> A, Map<String, Integer> B) {
        for (String key : A.keySet()) {
            if (!B.containsKey(key) || !A.get(key).equals(B.get(key))) {
                return false;
            }
        }
        return true;
    }

    public List<Integer> findSubstring(String s, String[] words) {
        List<Integer> res = new ArrayList<>();
        int word_len = words[0].length(), all_len = words.length * word_len;
        Map<String, Integer> wordCounter = new HashMap<>();
        for (String word : words) {
            wordCounter.put(word, wordCounter.getOrDefault(word, 0) + 1);
        }
        for (int i = 0; i < word_len; ++i) {
            Map<String, Integer> tempCounter = new HashMap<>();
            int left = i, right = i + all_len - word_len;
            for (int j = left; j < right; j += word_len) {
                String word = s.substring(j, j + word_len);
                tempCounter.put(word, tempCounter.getOrDefault(word, 0) + 1);
            }
            for (; right + word_len <= s.length(); left += word_len, right += word_len) {
                String word = s.substring(right, right + word_len);
                tempCounter.put(word, tempCounter.getOrDefault(word, 0) + 1);
                if (valid(wordCounter, tempCounter)) {
                    res.add(left);
                }
                word = s.substring(left, left + word_len);
                tempCounter.put(word, tempCounter.get(word) - 1);
            }
        }
        return res;
    }
}
