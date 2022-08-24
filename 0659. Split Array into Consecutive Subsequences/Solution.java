class Solution {
    public boolean isPossible(int[] nums) {
        int dp1 = 0, dp2 = 0, dp3 = 0;
        int i = 0;
        while (i < nums.length) {
            int beg = i++;
            while (i < nums.length && nums[beg] == nums[i]) {
                ++i;
            }
            int cnt = i - beg;

            if (beg > 0 && nums[beg] != nums[beg - 1] + 1) {
                if (dp1 + dp2 > 0) {
                    return false;
                }
                dp2 = dp3 = 0;
                dp1 = cnt;
            } else {
                if (dp1 + dp2 > cnt) {
                    return false;
                }
                int remain = cnt - dp1 - dp2;
                int temp = Math.min(remain, dp3);
                dp3 = temp + dp2;
                dp2 = dp1;
                dp1 = remain - temp;
            }
        }
        return dp1 == 0 && dp2 == 0;
    }
}
