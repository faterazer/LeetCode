import java.util.Arrays;

class Solution {
    /**
     * Sort
     * Time complexity: O(nlgn)
     * Space complexity: O(1)
     */
    public int arrayPairSum_MK1(int[] nums) {
        Arrays.sort(nums);
        int ret = 0;
        for (int i = 0; i < nums.length; i += 2)
            ret += nums[i];
        return ret;
    }

    /**
     * Hash
     * Time complexity: O(n)
     * Spacce complexity: O(1)
     */
    public int arrayPairSum_MK2(int[] nums) {
        int[] hash = new int[20001];
        for (int num : nums)
            hash[num + 10000]++;
        int d = 0, ret = 0;
        for (int i = 0; i < hash.length; i++) {
            if (hash[i] != 0) {
                ret += (hash[i] - d + 1) / 2 * (i - 10000);
                d = (hash[i] - d) % 2;
            }
        }
        return ret;
    }
}
