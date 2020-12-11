import java.util.*;

class Solution {
    public String mostCommonWord(String paragraph, String[] banned) {
        Set<String> ban = new HashSet<>(Arrays.asList(banned));
        Map<String, Integer> counter = new HashMap<>();
        String[] words = paragraph.replaceAll("\\W+", " ").toLowerCase().split("\\s+");
        for (String word : words) {
            if (!ban.contains(word)) {
                counter.put(word, counter.getOrDefault(word, 0) + 1);
            }
        }
        return Collections.max(counter.entrySet(), Map.Entry.comparingByValue()).getKey();
    }
}
