class Solution {
    public int dominantIndex(int[] nums) {
        int index = 0, second = -1;
        for (int i = 1; i < nums.length; i++) {
            if (nums[i] > nums[index]) {
                second = nums[index];
                index = i;
            }
            else if (nums[i] > second)
                second = nums[i];
        }
        return second * 2 <= nums[index] ? index : -1;
    }
}
