import java.util.Arrays;

class Solution {
    public int minOperations(int[] nums, int x) {
        int sum = Arrays.stream(nums).sum();

        int left = 0, right = 0, windowSum = 0, res = Integer.MAX_VALUE;
        for (; right < nums.length; right++) {
            windowSum += nums[right];
            while (left <= right && sum - windowSum < x) {
                windowSum -= nums[left++];
            }
            if (sum - windowSum == x) {
                res = Math.min(res, nums.length - right + left - 1);
            }
        }
        return res == Integer.MAX_VALUE ? -1 : res;
    }
}
