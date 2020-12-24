import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

class Solution {
    public String[] uncommonFromSentences(String A, String B) {
        StringBuilder sb = new StringBuilder(A).append(" ").append(B);
        String[] words = sb.toString().split(" ");
        Map<String, Integer> counter = new HashMap<>();
        for (String word : words) {
            counter.put(word, counter.getOrDefault(word, 0) + 1);
        }
        List<String> ret = new ArrayList<>();
        for (String s : counter.keySet()) {
            if (counter.get(s) == 1) {
                ret.add(s);
            }
        }
        return ret.toArray(new String[0]);
    }
}
