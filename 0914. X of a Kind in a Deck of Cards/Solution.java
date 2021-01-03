import java.util.HashMap;
import java.util.Map;

class Solution {
    public boolean hasGroupsSizeX(int[] deck) {
        Map<Integer, Integer> count = new HashMap<>();
        for (int x : deck) {
            count.put(x, count.getOrDefault(x, 0) + 1);
        }
        int res = 0;
        for (Integer value : count.values()) {
            res = gcd(res, value);
        }
        return res > 1;
    }

    private int gcd(int a, int b) {
        if (b == 0)
            return a;
        return gcd(b, a % b);
    }
}
