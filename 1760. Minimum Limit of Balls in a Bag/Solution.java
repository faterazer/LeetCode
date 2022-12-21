import java.util.Arrays;

class Solution {
    public int minimumSize(int[] nums, int maxOperations) {
        int left = 1, right = Arrays.stream(nums).max().orElse(0);
        while (left < right) {
            int mid = left + ((right - left) >> 1);
            int count = 0;
            for (int num : nums) {
                count += (num - 1) / mid;
            }
            if (count > maxOperations) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return left;
    }
}
