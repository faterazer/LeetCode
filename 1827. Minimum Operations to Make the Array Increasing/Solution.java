class Solution {
    public int minOperations(int[] nums) {
        int res = 0, prev = 0;
        for (int x : nums) {
            if (x <= prev) {
                res += ++prev - x;
            } else{
                prev = x;
            }
        }
        return res;
    }
}
