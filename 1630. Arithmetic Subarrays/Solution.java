import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

class Solution {
    private boolean check(int[] nums, int left, int right) {
        Set<Integer> set = new HashSet<>();
        int minVal = Integer.MAX_VALUE, maxVal = Integer.MIN_VALUE, len = right - left + 1;
        for (int i = left; i <= right; i++) {
            set.add(nums[i]);
            minVal = Math.min(minVal, nums[i]);
            maxVal = Math.max(maxVal, nums[i]);
        }
        if ((maxVal - minVal) % (len - 1) != 0) {
            return false;
        }
        int d = (maxVal - minVal) / (len - 1);
        for (int i = 1; i < len; i++) {
            if (!set.contains(minVal + (i - 1) * d)) {
                return false;
            }
        }
        return true;
    }

    public List<Boolean> checkArithmeticSubarrays(int[] nums, int[] l, int[] r) {
        int n = l.length;
        List<Boolean> res = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            res.add(check(nums, l[i], r[i]));
        }
        return res;
    }
}
