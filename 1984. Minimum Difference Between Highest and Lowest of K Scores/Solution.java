import java.util.Arrays;

class Solution {
    public int minimumDifference(int[] nums, int k) {
        Arrays.sort(nums);
        int res = Integer.MAX_VALUE;
        for (int i = k - 1; i < nums.length; i++) {
            res = Math.min(res, nums[i] - nums[i - k + 1]);
        }
        return res;
    }
}
