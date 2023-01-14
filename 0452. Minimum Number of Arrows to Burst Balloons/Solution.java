import java.util.Arrays;
import java.util.Comparator;

class Solution {
    public int findMinArrowShots(int[][] points) {
        Arrays.sort(points, Comparator.comparingInt(x -> x[1]));

        int res = 1, position = points[0][1];
        for (int[] point : points) {
            if (point[0] > position) {
                position = point[1];
                ++res;
            }
        }
        return res;
    }
}
