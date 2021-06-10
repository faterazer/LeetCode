import java.util.Arrays;
import java.util.Comparator;

class Solution {
    public String sortSentence(String s) {
        String[] arr = s.split(" ");
        Arrays.sort(arr, Comparator.comparingInt(a -> a.charAt(a.length() - 1)));
        StringBuilder sb = new StringBuilder();
        for (String word : arr) {
            sb.append(word, 0, word.length() - 1).append(" ");
        }
        return sb.substring(0, sb.length() - 1);
    }
}
