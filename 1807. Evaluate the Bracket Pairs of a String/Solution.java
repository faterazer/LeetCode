import java.util.HashMap;
import java.util.List;
import java.util.Map;

class Solution {
    public String evaluate(String s, List<List<String>> knowledge) {
        Map<String, String> mapper = new HashMap<>();
        for (List<String> k : knowledge) {
            mapper.put(k.get(0), k.get(1));
        }

        boolean IN = false;
        StringBuilder key = new StringBuilder();
        StringBuilder res = new StringBuilder();
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == '(') {
                key.setLength(0);
                IN = true;
            } else if (s.charAt(i) == ')') {
                res.append(mapper.getOrDefault(key.toString(), "?"));
                IN = false;
            } else if (IN) {
                key.append(s.charAt(i));
            } else {
                res.append(s.charAt(i));
            }
        }
        return res.toString();
    }
}
