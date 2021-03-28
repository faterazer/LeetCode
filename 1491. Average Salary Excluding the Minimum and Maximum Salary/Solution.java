class Solution {
    public double average(int[] salary) {
        int sum = 0, max = salary[0], min = salary[0];
        for (int x : salary) {
            sum += x;
            max = Math.max(max, x);
            min = Math.min(min, x);
        }
        return (double)(sum - max - min) / (salary.length - 2);
    }
}
