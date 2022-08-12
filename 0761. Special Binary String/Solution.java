import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

class Solution {
    public String makeLargestSpecial(String s) {
        if (s.length() <= 2) {
            return s;
        }

        int count = 0, last = 0;
        List<String> subStrings = new ArrayList<>();
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == '1') {
                ++count;
            } else {
                --count;
                if (count == 0) {
                    subStrings.add("1" + makeLargestSpecial(s.substring(last + 1, i)) + "0");
                    last = i + 1;
                }
            }
        }
        subStrings.sort(Collections.reverseOrder());
        return String.join("", subStrings);
    }
}
