class Solution {
    public int majorityElement(int[] nums) {
        int majority = 0, count = 0;
        for (int num : nums) {
            if (count == 0) {
                majority = num;
            }
            count += majority == num ? 1 : -1;
        }
        return majority;
    }
}
