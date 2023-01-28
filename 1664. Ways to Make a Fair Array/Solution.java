class Solution {
    public int waysToMakeFair(int[] nums) {
        int res = 0, s = 0;
        for (int i = 0; i < nums.length; i++) {
            s += i % 2 == 1 ? -nums[i] : nums[i];
        }
        for (int i = 0; i < nums.length; i++) {
            s += i % 2 == 1 ? nums[i] : -nums[i];
            if (s == 0) {
                ++res;
            }
            s += i % 2 == 1 ? nums[i] : -nums[i];
        }
        return res;
    }
}
