class Solution {
    public int maximumDifference(int[] nums) {
        int res = -1, minimum = Integer.MAX_VALUE;
        for (int e : nums) {
            if (e > minimum) {
                res = Math.max(res, e - minimum);
            } else {
                minimum = e;
            }
        }
        return res;
    }
}
