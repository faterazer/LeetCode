class Solution {
    public int maxScore(int[] cardPoints, int k) {
        int windowSize = cardPoints.length - k;
        int allSum = 0, windowSum = 0;
        for (int i = 0; i < windowSize; i++) {
            windowSum += cardPoints[i];
            allSum += cardPoints[i];
        }

        int minSum = windowSum;
        for (int i = windowSize; i < cardPoints.length; i++) {
            windowSum += cardPoints[i] - cardPoints[i - windowSize];
            minSum = Math.min(minSum, windowSum);
            allSum += cardPoints[i];
        }
        return allSum - minSum;
    }
}
