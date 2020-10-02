import java.util.HashSet;
import java.util.Set;

class Solution {
    public int numJewelsInStones(String J, String S) {
        Set<Character> hash = new HashSet<>();
        for (int i = 0; i < J.length(); i++)
            hash.add(J.charAt(i));
        int count = 0;
        for (int i = 0; i < S.length(); i++) {
            if (hash.contains(S.charAt(i)))
                count += 1;
        }
        return count;
    }
}

