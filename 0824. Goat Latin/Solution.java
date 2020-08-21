import java.util.Arrays;
import java.util.HashSet;
import java.util.Set;
import java.util.StringJoiner;

class Solution {
    public String toGoatLatin(String S) {
        Set<Character> vowels = new HashSet<>(Arrays.asList('a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'));
        StringJoiner ret = new StringJoiner(" ");
        String suff = "";
        for (String word : S.split(" ")) {
            suff += "a";
            if (!vowels.contains(word.charAt(0)))
                word = word.substring(1) + word.charAt(0);
            word += "ma" + suff;
            ret.add(word);
        }
        return ret.toString();
    }
}
