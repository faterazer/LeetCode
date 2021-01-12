import java.util.HashMap;
import java.util.Map;

class Solution {
    public boolean isAlienSorted(String[] words, String order) {
        Map<Character, Integer> dict = new HashMap<>();
        for (int i = 0; i < order.length(); i++) {
            dict.put(order.charAt(i), i + 1);
        }
        for (int i = 1; i < words.length; i++) {
            if (wordCmp(words[i - 1], words[i], dict) > 0)
                return false;
        }
        return true;
    }

    private int wordCmp(String s1, String s2, Map<Character, Integer> dict) {
        int i = 0, j = 0;
        while (i < s1.length() && j < s2.length() && s1.charAt(i) == s2.charAt(j)) {
            i++;
            j++;
        }
        int a = i == s1.length() ? 0 : dict.get(s1.charAt(i));
        int b = j == s2.length() ? 0 : dict.get(s2.charAt(j));
        return a - b;
    }
}
