import java.util.ArrayList;
import java.util.List;

class Solution {
    public List<Boolean> camelMatch(String[] queries, String pattern) {
        List<Boolean> res = new ArrayList<>();
        for (String query : queries) {
            int i = 0, j = 0;
            for (; i < query.length(); i++) {
                if (j < pattern.length() && query.charAt(i) == pattern.charAt(j)) {
                    j++;
                } else if (Character.isUpperCase(query.charAt(i))) {
                    break;
                }
            }
            res.add(i == query.length() && j == pattern.length());
        }
        return res;
    }
}
