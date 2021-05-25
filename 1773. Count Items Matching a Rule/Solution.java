import java.util.List;
import java.util.Map;

class Solution {
    private final Map<String, Integer> key2idx = Map.of("type", 0, "color", 1, "name", 2);

    public int countMatches(List<List<String>> items, String ruleKey, String ruleValue) {
        return (int)items.stream().filter(item -> item.get(key2idx.get(ruleKey)).equals(ruleValue)).count();
    }
}
