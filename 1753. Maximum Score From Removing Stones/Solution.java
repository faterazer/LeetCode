class Solution {
    public int maximumScore(int a, int b, int c) {
        int sum = a + b + c;
        int maxVal = Math.max(a, Math.max(b, c));
        return Math.min(sum - maxVal, sum / 2);
    }
}
