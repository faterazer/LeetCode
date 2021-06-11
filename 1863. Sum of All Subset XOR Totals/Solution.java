class Solution {
    public int subsetXORSum(int[] nums) {
        int res = 0;
        for (int num : nums) {
            res |= num;
        }
        return res << (nums.length - 1);
    }
}
