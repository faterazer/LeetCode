class Solution {
    public int partitionDisjoint(int[] nums) {
        int res = 1, lastMax = nums[0], curMax = nums[0];
        for (int i = 1; i < nums.length; i++) {
            if (nums[i] < lastMax) {
                res = i + 1;
                lastMax = curMax;
            } else {
                curMax = Math.max(curMax, nums[i]);
            }
        }
        return res;
    }
}
