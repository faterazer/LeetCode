import java.util.HashSet;
import java.util.Set;

class Solution {
    public boolean findSubarrays(int[] nums) {
        Set<Integer> set = new HashSet<>();
        for (int i = 1; i < nums.length; i++) {
            if (!set.add(nums[i - 1] + nums[i])) {
                return true;
            }
        }
        return false;
    }
}
