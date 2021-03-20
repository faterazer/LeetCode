class Solution {
    public int[] shuffle(int[] nums, int n) {
        for (int i = 0; i < nums.length; i++) {
            nums[i] <<= 10;
        }
        for (int i = 0, j = n, k = 0; i < n; i++, j++, k += 2) {
            nums[k] |= nums[i] >> 10;
            nums[k + 1] |= nums[j] >> 10;
        }
        for (int i = 0; i < nums.length; i++) {
            nums[i] &= 0x3FF;
        }
        return nums;
    }
}
