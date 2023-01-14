import java.util.HashMap;
import java.util.Map;

class Solution {
    public boolean digitCount(String num) {
        Map<Integer, Integer> counter = new HashMap<>();
        for (int i = 0; i < num.length(); i++) {
            int digit = num.charAt(i) - '0';
            counter.put(digit, counter.getOrDefault(digit, 0) + 1);
        }
        for (int i = 0; i < num.length(); i++) {
            if (counter.getOrDefault(i, 0) != num.charAt(i) - '0') {
                return false;
            }
        }
        return true;
    }
}
