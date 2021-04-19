class Solution {
    public int specialArray(int[] nums) {
        int n = nums.length, cnt = 0;
        int[] counter = new int[n + 1];
        for (int num : nums) {
            counter[Math.min(num, n)]++;
        }
        for (int i = n; i > 0; i--) {
            cnt += counter[i];
            if (cnt == i) {
                return i;
            }
        }
        return -1;
    }
}
