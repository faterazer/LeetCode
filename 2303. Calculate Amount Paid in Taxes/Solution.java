class Solution {
    public double calculateTax(int[][] brackets, int income) {
        double tax = 0.0, prev = 0.0;
        for (int[] bracket : brackets) {
            int upper = bracket[0], percent = bracket[1];
            tax += (Math.min(income, upper) - prev) * percent / 100;
            prev = upper;
            if (income <= upper) {
                break;
            }
        }
        return tax;
    }
}
