class Solution {
    public int arraySign(int[] nums) {
        int res = 1;
        for (int x : nums) {
            if (x < 0) {
                res *= -1;
            } else if (x == 0) {
                return 0;
            }
        }
        return res;
    }
}
