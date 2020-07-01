class Solution {
    public int findMaxConsecutiveOnes(int[] nums) {
        int maximum = 0, count = 0;
        for (int n : nums) {
            if (n == 1)
                count++;
            else {
                maximum = Math.max(maximum, count);
                count = 0;
            }
        }
        return Math.max(maximum, count);
    }
}
