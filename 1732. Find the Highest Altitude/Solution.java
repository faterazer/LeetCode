class Solution {
    public int largestAltitude(int[] gain) {
        int res = 0, altitude = 0;
        for (int x : gain) {
            altitude += x;
            res = Math.max(res, altitude);
        }
        return res;
    }
}
