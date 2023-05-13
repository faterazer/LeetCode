import java.util.HashSet;
import java.util.Set;

class Solution {
    public int findMaxK(int[] nums) {
        int res = -1;
        Set<Integer> seen = new HashSet<>();
        for (int num : nums) {
            if (seen.contains(-num)) {
                res = Math.max(res, Math.abs(num));
            }
            seen.add(num);
        }
        return res;
    }
}
