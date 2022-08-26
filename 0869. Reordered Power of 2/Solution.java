import java.util.Arrays;
import java.util.HashSet;
import java.util.Set;

class Solution {
    private final Set<String> nums = new HashSet<>();

    Solution() {
        for (int i = 0; i < 32; i++) {
            char[] x = String.valueOf(1 << i).toCharArray();
            Arrays.sort(x);
            nums.add(new String(x));
        }
    }

    public boolean reorderedPowerOf2(int n) {
        char[] x = String.valueOf(n).toCharArray();
        Arrays.sort(x);
        return nums.contains(new String(x));
    }
}
