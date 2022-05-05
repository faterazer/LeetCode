class Solution {
    public int numSubarrayProductLessThanK(int[] nums, int k) {
        int i = 0, prod = 1;
        int res = 0;
        for (int j = 0; j < nums.length; j++) {
            prod *= nums[j];
            while (i <= j && prod >= k) {
                prod /= nums[i++];
            }
            res += j - i + 1;
        }
        return res;
    }
}
