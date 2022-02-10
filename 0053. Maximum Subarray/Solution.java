class Solution {
    public int maxSubArray(int[] nums) {
        int res = Integer.MIN_VALUE, cur = 0;
        for (int e : nums) {
            if (cur < 0) {
                cur = e;
            } else {
                cur += e;
            }
            res = Math.max(res, cur);
        }
        return res;
    }
}
