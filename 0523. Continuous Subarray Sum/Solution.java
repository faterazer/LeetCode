import java.util.HashMap;
import java.util.Map;

class Solution {
    public boolean checkSubarraySum(int[] nums, int k) {
        int preSum = 0;
        Map<Integer, Integer> idxMap = new HashMap<>();
        idxMap.put(0, -1);
        for (int i = 0; i < nums.length; i++) {
            preSum += nums[i];
            int remainder = preSum % k;
            if (idxMap.containsKey(remainder) && i - idxMap.get(remainder) > 1) {
                return true;
            } else if (!idxMap.containsKey(remainder)) {
                idxMap.put(remainder, i);
            }
        }
        return false;
    }
}
