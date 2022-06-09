import java.util.Random;

class Solution {
    private final double xCenter;
    private final double yCenter;
    private final double radius;
    private final Random random;

    public Solution(double radius, double xCenter, double yCenter) {
        this.xCenter = xCenter;
        this.yCenter = yCenter;
        this.radius = radius;
        random = new Random();
    }

    public double[] randPoint() {
        double r = Math.sqrt(random.nextDouble()), theta = random.nextDouble() * 2 * Math.PI;
        return new double[]{xCenter + r * Math.cos(theta) * radius, yCenter + r * Math.sin(theta) * radius};
    }
}

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(radius, x_center, y_center);
 * double[] param_1 = obj.randPoint();
 */
