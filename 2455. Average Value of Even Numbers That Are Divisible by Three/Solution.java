class Solution {
    public int averageValue(int[] nums) {
        int sum = 0, cnt = 0;
        for (int x : nums) {
            if (x % 6 == 0) {
                sum += x;
                cnt++;
            }
        }
        return cnt == 0 ? 0 : sum / cnt;
    }
}
