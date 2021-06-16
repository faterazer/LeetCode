class Solution {
    public boolean isCovered(int[][] ranges, int left, int right) {
        int n = right - left + 1, count = 0;
        int[] range = new int[n];
        for (int[] r : ranges) {
            if (r[0] < left) {
                count++;
            } else if (r[0] <= right) {
                range[r[0] - left]++;
            }
            if (r[1] < left) {
                count--;
            } else if (r[1] < right) {
                range[r[1] - left + 1]--;
            }
        }
        for (int x : range) {
            count += x;
            if (count == 0) {
                return false;
            }
        }
        return true;
    }
}
