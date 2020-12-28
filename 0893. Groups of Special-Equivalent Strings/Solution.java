import java.util.Arrays;
import java.util.HashSet;
import java.util.Set;

class Solution {
    public int numSpecialEquivGroups(String[] A) {
        Set<String> seen = new HashSet<>();
        for (String s : A) {
            int[] counter = new int[52];
            for (int i = 0; i < s.length(); i++) {
                counter[s.charAt(i) - 'a' + 26 * (i % 2)]++;
            }
            seen.add(Arrays.toString(counter));
        }
        return seen.size();
    }
}
