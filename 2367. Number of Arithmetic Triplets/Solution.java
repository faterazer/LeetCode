class Solution {
    public int arithmeticTriplets(int[] nums, int diff) {
        int res = 0, i = 0, j = 0;
        for (int x : nums) {
            while (nums[j] + diff < x) {
                j++;
            }
            if (nums[j] + diff > x) {
                continue;
            }
            while (nums[i] + 2 * diff < x) {
                i++;
            }
            if (nums[i] + 2 * diff == x) {
                res++;
            }
        }
        return res;
    }
}
