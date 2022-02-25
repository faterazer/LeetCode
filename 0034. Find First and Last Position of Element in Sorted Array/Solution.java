class Solution {
    public int[] searchRange(int[] nums, int target) {
        int[] res = new int[]{-1, -1};
        if (nums.length == 0) {
            return res;
        }
        int l = 0, r = nums.length, m;
        while (l < r) {
            m = l + ((r - l) >> 1);
            if (nums[m] < target) {
                l = m + 1;
            } else {
                r = m;
            }
        }
        if (l >= nums.length || nums[l] != target) {
            return res;
        } else {
            res[0] = l;
        }
        r = nums.length;
        while (l < r) {
            m = l + ((r - l) >> 1);
            if (nums[m] <= target) {
                l = m + 1;
            } else {
                r = m;
            }
        }
        res[1] = l - 1;
        return res;
    }
}
