class Solution {
    public double largestTriangleArea(int[][] points) {
        double res = 0.0;
        for (int i = 0; i < points.length - 2; i++)
            for (int j = i + 1; j < points.length - 1; j++)
                for (int k = j + 1; k < points.length; k++)
                    res = Math.max(res, area(points[i], points[j], points[k]));
        return res;
    }

    private double area(int[] a, int[] b, int[] c) {
        return 0.5 * Math.abs((a[0] - b[0]) * (c[1] - b[1]) - (a[1] - b[1]) * (c[0] - b[0]));
    }
}
