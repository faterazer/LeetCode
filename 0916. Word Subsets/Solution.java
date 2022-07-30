import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

class Solution {
    private Map<Character, Integer> wordCount(String word) {
        Map<Character, Integer> res = new HashMap<>();
        for (int i = 0; i < word.length(); i++) {
            res.put(word.charAt(i), res.getOrDefault(word.charAt(i), 0) + 1);
        }
        return res;
    }

    public List<String> wordSubsets(String[] words1, String[] words2) {
        Map<Character, Integer> count = new HashMap<>();
        for (String word : words2) {
            Map<Character, Integer> temp = wordCount(word);
            for (Map.Entry<Character, Integer> entry : temp.entrySet()) {
                count.put(entry.getKey(), Math.max(count.getOrDefault(entry.getKey(), 0), entry.getValue()));
            }
        }

        List<String> res = new ArrayList<>();
        for (String word : words1) {
            Map<Character, Integer> temp = wordCount(word);
            boolean flag = true;
            for (Map.Entry<Character, Integer> entry : count.entrySet()) {
                if (!temp.containsKey(entry.getKey()) || temp.get(entry.getKey()) < entry.getValue()) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                res.add(word);
            }
        }
        return res;
    }
}
