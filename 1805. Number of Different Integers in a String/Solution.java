import java.util.Collections;
import java.util.HashSet;
import java.util.Set;

class Solution {
    public int numDifferentIntegers(String word) {
        Set<String> set = new HashSet<>(Collections.singletonList(""));
        int i = 0;
        for (int j = 0; j < word.length(); j++) {
            if (Character.isDigit(word.charAt(j))) {
                if (i < j && word.charAt(i) == '0') {
                    i++;
                }
            } else {
                set.add(word.substring(i, j));
                i = j + 1;
            }
        }
        set.add(word.substring(i));
        return set.size() - 1;
    }
}
