/**
 * Time complexity: O(n).
 * Space complexity: O(1).
 */
class Solution {
    public int[] findErrorNums(int[] nums) {
        int sum = 0, dup = 0, n = nums.length;
        for (int num : nums) {
            if (nums[Math.abs(num) - 1] < 0)
                dup = Math.abs(num);
            else
                nums[Math.abs(num) - 1] *= -1;
            sum += Math.abs(num);
        }
        return new int[]{dup, (1 + n) * n / 2 - sum + dup};
    }
}
