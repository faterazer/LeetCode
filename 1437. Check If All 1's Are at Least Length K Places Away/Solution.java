class Solution {
    public boolean kLengthApart(int[] nums, int k) {
        int gap = k;
        for (int x : nums) {
            if (x == 1) {
                if (gap < k) {
                    return false;
                }
                gap = 0;
            } else {
                gap++;
            }
        }
        return true;
    }
}
