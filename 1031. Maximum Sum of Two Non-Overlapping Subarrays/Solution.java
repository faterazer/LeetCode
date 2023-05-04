class Solution {
    private int helper(int[] nums, int firstLen, int secondLen) {
        int firstSum = 0;
        for (int i = 0; i < firstLen; i++) {
            firstSum += nums[i];
        }
        int maxFirstSum = firstSum, secondSum = 0;
        for (int i = firstLen; i < firstLen + secondLen; i++) {
            secondSum += nums[i];
        }
        int res = maxFirstSum + secondSum;
        for (int i = firstLen; i + secondLen < nums.length; i++) {
            firstSum += nums[i] - nums[i - firstLen];
            maxFirstSum = Math.max(maxFirstSum, firstSum);
            secondSum += nums[i + secondLen] - nums[i];
            res = Math.max(res, maxFirstSum + secondSum);
        }
        return res;
    }

    public int maxSumTwoNoOverlap(int[] nums, int firstLen, int secondLen) {
        return Math.max(helper(nums, firstLen, secondLen), helper(nums, secondLen, firstLen));
    }
}
