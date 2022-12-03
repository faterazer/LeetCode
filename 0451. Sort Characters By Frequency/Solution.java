import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

class Solution {
    public String frequencySort(String s) {
        Map<Character, Integer> counter = new HashMap<>();
        for (int i = 0; i < s.length(); i++) {
            counter.put(s.charAt(i), counter.getOrDefault(s.charAt(i), 0) + 1);
        }
        List<Character> charList = new ArrayList<>(counter.keySet());
        charList.sort((a, b) -> counter.get(b) - counter.get(a));
        StringBuilder sb = new StringBuilder();
        for (Character ch : charList) {
            sb.append(String.valueOf(ch).repeat(counter.get(ch)));
        }
        return sb.toString();
    }
}
