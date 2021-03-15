class Solution {
    public int minStartValue(int[] nums) {
        int sum = 0, minSum = 0;
        for (int x : nums) {
            sum += x;
            minSum = Math.min(sum, minSum);
        }
        return 1 - minSum;
    }
}
