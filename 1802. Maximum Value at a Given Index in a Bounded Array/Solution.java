class Solution {
    public int maxValue(int n, int index, int maxSum) {
        double left = index, right = n - index - 1;
        if (left > right) {
            double temp = left;
            left = right;
            right = temp;
        }

        double upper = left * left + 3 * left + right + 1;
        if (upper >= maxSum) {
            double a = 1, b = -2, c = left + right + 2 - maxSum;
            return (int) Math.floor((-b + Math.sqrt(b * b - 4 * a * c)) / (2 * a));
        }

        upper = (2.0 * (right + 1) - left - 1) * left / 2 + (right + 1) + ((right + 1) * (right + 1) - 3 * (right + 1)) / 2 + right + 1;
        if (upper >= maxSum) {
            double a = 1.0 / 2;
            double b = left + 1 - 3.0 / 2;
            double c = right + 1 + (-left - 1) * left / 2 - maxSum;
            return (int) Math.floor((-b + Math.sqrt(b * b - 4 * a * c)) / (2 * a));
        } else {
            double a = left + right + 1;
            double b = (-left * left - left - right * right - right) / 2 - maxSum;
            return (int) Math.floor(-b / a);
        }
    }
}
