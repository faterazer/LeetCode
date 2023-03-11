import java.util.HashMap;
import java.util.Map;

class Solution {
    public int minSubarray(int[] nums, int p) {
        int allSum = 0;
        for (int num : nums) {
            allSum = (allSum + num) % p;
        }
        if (allSum == 0) {
            return 0;
        }

        int res = nums.length, preSum = 0;
        Map<Integer, Integer> memo = new HashMap<>();
        memo.put(0, -1);
        for (int i = 0; i < nums.length; i++) {
            preSum = (preSum + nums[i]) % p;
            memo.put(preSum, i);
            int need = (preSum - allSum + p) % p;
            if (memo.containsKey(need)) {
                res = Math.min(res, i - memo.get(need));
            }
        }
        return res < nums.length ? res : -1;
    }
}
