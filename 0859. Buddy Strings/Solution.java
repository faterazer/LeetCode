import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

class Solution {
    public boolean buddyStrings(String A, String B) {
        if (A.length() != B.length())
            return false;
        Set<Character> set = new HashSet<>();
        List<Integer> diff = new ArrayList<>();
        for (int i = 0; i < A.length(); i++) {
            set.add(A.charAt(i));
            if (A.charAt(i) != B.charAt(i)) {
                if (diff.size() == 2)
                    return false;
                diff.add(i);
            }
        }
        if (diff.size() == 0)
            return set.size() < A.length();
        else if (diff.size() == 1)
            return false;
        else
            return A.charAt(diff.get(0)) == B.charAt(diff.get(1)) && A.charAt(diff.get(1)) == B.charAt(diff.get(0));
    }
}
