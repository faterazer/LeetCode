import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;

class Solution {
    /**
     * Hash
     * Time complexity: O(n)
     * Space complexity: O(1)
     */
    public int findLHS_MK1(int[] nums) {
        Map<Integer, Integer> map = new HashMap<>();
        for (int n : nums)
            map.put(n, map.getOrDefault(n, 0) + 1);
        int ret = 0;
        for (int key : map.keySet()) {
            if (map.containsKey(key + 1))
                ret = Math.max(ret, (map.get(key) + map.get(key + 1)));
        }
        return ret;
    }

    /**
     * Sort
     * Time complexity: O(n)
     * Space complexity: O(1)
     */
    public int findLHS_MK2(int[] nums) {
        Arrays.sort(nums);
        int beg = 0, newBeg = 0, ret = 0;
        for (int i = 1; i < nums.length; i++) {
            if (nums[i] - nums[beg] > 1)
                beg = newBeg;
            if (nums[i] != nums[i - 1])
                newBeg = i;
            if (nums[i] - nums[beg] == 1)
                ret = Math.max(ret, i - beg + 1);
        }
        return ret;
    }
}
