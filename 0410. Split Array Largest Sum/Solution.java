class Solution {
    public int splitArray(int[] nums, int m) {
        int left = 0, right = 0;
        for (int num : nums) {
            left = Math.max(left, num);
            right += num;
        }
        while (left < right) {
            int mid = left + ((right - left) >> 1);
            if (valid(nums, m, mid)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return right;
    }

    private boolean valid(int[] nums, int m, int sumLimit) {
        int sum = 0, count = 1;
        for (int num : nums) {
            if (sum + num <= sumLimit) {
                sum += num;
            } else {
                sum = num;
                count += 1;
            }
        }
        return count <= m;
    }
}
