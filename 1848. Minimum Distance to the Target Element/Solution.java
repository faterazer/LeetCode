class Solution {
    public int getMinDistance(int[] nums, int target, int start) {
        int res = Integer.MAX_VALUE;
        for (int i = 0; i < nums.length && res != 0; i++) {
            if (nums[i] == target) {
                int diff = Math.abs(i - start);
                if (diff >= res) {
                    return res;
                } else {
                    res = diff;
                }
            }
        }
        return res;
    }
}
