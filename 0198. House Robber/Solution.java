class Solution {
    public int rob(int[] nums) {
        int prevMax = 0, currMax = 0;
        for (int num : nums) {
            int tmp = currMax;
            currMax = Math.max(currMax, prevMax + num);
            prevMax = tmp;
        }
        return currMax;
    }
}
