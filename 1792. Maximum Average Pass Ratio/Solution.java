import java.util.Comparator;
import java.util.PriorityQueue;

class Solution {
    private double profit(double a, double b) {
        return (a + 1) / (b + 1) - a / b;
    }

    public double maxAverageRatio(int[][] classes, int extraStudents) {
        PriorityQueue<double[]> heap = new PriorityQueue<>(Comparator.comparingDouble(o -> -o[0]));
        for (int[] c : classes) {
            heap.offer(new double[]{profit(c[0], c[1]), c[0], c[1]});
        }
        while (extraStudents-- > 0) {
            double[] top = heap.remove();
            double a = top[1] + 1, b = top[2] + 1;
            heap.offer(new double[]{profit(a, b), a, b});
        }

        double res = 0.0;
        while (!heap.isEmpty()) {
            double[] top = heap.remove();
            double a = top[1], b = top[2];
            res += a / b;
        }
        return res / classes.length;
    }
}
