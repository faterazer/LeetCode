import java.util.HashSet;
import java.util.Set;

class Solution {
    private boolean check(String s, int k, int lower, int upper) {
        if (lower > upper) {
            return true;
        }
        Set<Integer> seen = new HashSet<>();
        int offset = k - 1, mask = (1 << offset) - 1;
        int x = Integer.parseInt(s.substring(0, k - 1), 2);
        for (int i = k - 1; i < s.length(); i++) {
            x = ((x & mask) << 1) | (s.charAt(i) - '0');
            if (lower <= x && x <= upper) {
                seen.add(x);
            }
        }
        return seen.size() == upper - lower + 1;
    }

    public boolean queryString(String s, int n) {
        if (n == 1) {
            return s.contains("1");
        }
        int k = 31 - Integer.numberOfLeadingZeros(n);
        if (s.length() < Math.max(k + (1 << (k - 1)) - 1, n - (1 << k) + k + 1)) {
            return false;
        }
        return check(s, k, n / 2 + 1, (1 << k) - 1) && check(s, k + 1, 1 << k, n);
    }
}
