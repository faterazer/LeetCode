class Solution {
    /**
     * Time complexity: O(n)
     * Space complexity: O(1)
     */
    public int findUnsortedSubarray_MK1(int[] nums) {
        int beg = 0, end = nums.length - 1;
        while (beg < nums.length - 1 && nums[beg] <= nums[beg + 1])
            beg++;
        if (beg == nums.length - 1)
            return 0;
        while (end > 0 && nums[end] >= nums[end - 1])
            end--;
        int maxItem = Integer.MIN_VALUE, minItem = Integer.MAX_VALUE;
        for (int i = beg; i <= end; i++) {
            maxItem = Math.max(maxItem, nums[i]);
            minItem = Math.min(minItem, nums[i]);
        }
        beg = 0;
        while (nums[beg] <= minItem)
            beg++;
        end = nums.length - 1;
        while (nums[end] >= maxItem)
            end--;
        return end - beg + 1;
    }

    /**
     * More concise.
     * Time complexity: O(n)
     * Space complexity: O(1)
     */
    public int findUnsortedSubarray_MK2(int[] nums) {
        int maxItem = nums[0], minItem = nums[nums.length - 1];
        int beg = -1, end = -2;
        for (int i = 1; i < nums.length; i++) {
            maxItem = Math.max(maxItem, nums[i]);
            minItem = Math.min(minItem, nums[nums.length - 1 - i]);
            if (nums[i] < maxItem)
                end = i;
            if (nums[nums.length - 1 - i] > minItem)
                beg = nums.length - 1 - i;
        }
        return end - beg + 1;
    }
}
