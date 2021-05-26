class Solution {
    public int nearestValidPoint(int x, int y, int[][] points) {
        int res = -1, dist = Integer.MAX_VALUE;
        for (int i = 0; i < points.length; i++) {
            int xx = points[i][0], yy = points[i][1];
            if (xx == x || yy == y) {
                int tmp = Math.abs(xx - x) + Math.abs(yy - y);
                if (tmp < dist) {
                    dist = tmp;
                    res = i;
                }
            }
        }
        return res;
    }
}
