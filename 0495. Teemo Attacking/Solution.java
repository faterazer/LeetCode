class Solution {
    public int findPoisonedDuration(int[] timeSeries, int duration) {
        int res = 0, last = -1;
        for (int t : timeSeries) {
            res += t > last ? duration : t - last + duration;
            last = t + duration;
        }
        return res;
    }
}
