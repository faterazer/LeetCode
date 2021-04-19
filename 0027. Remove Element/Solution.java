class Solution {
    // 双指针法
    // Approach 1: Two Pointers
    public int removeElement_MK1(int[] nums, int val) {
        int last = 0;
        for (int num : nums) {
            if (num != val) {
                nums[last++] = num;
            }
        }
        return last;
    }

    // 改进的双指针法，当要删除的元素很少时，速度更快
    // Approach 2: Two Pointers - when elements to remove are rare
    public int removeElement_MK2(int[] nums, int val) {
        int len = nums.length;
        for (int i = 0; i < len; ) {
            if (nums[i] == val) {
                nums[i] = nums[--len];
            } else {
                i++;
            }
        }
        return len;
    }
}
