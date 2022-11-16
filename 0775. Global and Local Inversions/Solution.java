class Solution {
    public boolean isIdealPermutation_MK1(int[] nums) {
        int max = 0;
        for (int i = 0; i < nums.length - 2; i++) {
            max = Math.max(max, nums[i]);
            if (max > nums[i + 2]) {
                return false;
            }
        }
        return true;
    }

    public boolean isIdealPermutation_MK2(int[] nums) {
        for (int i = 0; i < nums.length; i++) {
            if (Math.abs(nums[i] - i) > 1) {
                return false;
            }
        }
        return true;
    }
}
