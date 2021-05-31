class Solution {
    public int maxAscendingSum(int[] nums) {
        int maxSum = nums[0], cur = nums[0];
        for (int i = 1; i < nums.length; i++) {
            if (nums[i] <= nums[i - 1]) {
                maxSum = Math.max(maxSum, cur);
                cur = 0;
            }
            cur += nums[i];
        }
        return Math.max(maxSum, cur);
    }
}
