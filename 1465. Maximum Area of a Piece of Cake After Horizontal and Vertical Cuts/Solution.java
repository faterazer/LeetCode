import java.util.Arrays;

class Solution {
    private int getMax(int n, int[] cuts) {
        Arrays.sort(cuts);
        int res = Math.max(cuts[0], n - cuts[cuts.length - 1]);
        for (int i = 1; i < cuts.length; i++) {
            res = Math.max(res, cuts[i] - cuts[i - 1]);
        }
        return res;
    }

    public int maxArea(int h, int w, int[] horizontalCuts, int[] verticalCuts) {
        final int P = 1000000007;
        return (int) ((long) getMax(h, horizontalCuts) * getMax(w, verticalCuts) % P);
    }
}
