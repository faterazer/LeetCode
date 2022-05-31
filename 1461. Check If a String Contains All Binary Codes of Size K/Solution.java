import java.util.HashSet;
import java.util.Set;

class Solution {
    public boolean hasAllCodes(String s, int k) {
        if (s.length() - k + 1 < (1 << k)) {
            return false;
        }
        int n = Integer.parseInt(s.substring(0, k), 2);
        Set<Integer> seen = new HashSet<>();
        seen.add(n);
        int head_mask = ~(1 << (k - 1));
        for (int i = k; i < s.length(); ++i) {
            n = (n & head_mask) << 1 | (s.charAt(i) - '0');
            seen.add(n);
        }
        return seen.size() == (1 << k);
    }
}
