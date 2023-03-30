import java.util.Arrays;
import java.util.Comparator;

class Solution {
    public int maxWidthOfVerticalArea(int[][] points) {
        Arrays.sort(points, Comparator.comparingInt(x -> x[0]));
        int res = 0;
        for (int i = 1; i < points.length; i++) {
            res = Math.max(res, points[i][0] - points[i - 1][0]);
        }
        return res;
    }
}
