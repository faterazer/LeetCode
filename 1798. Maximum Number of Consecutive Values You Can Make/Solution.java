import java.util.Arrays;

class Solution {
    public int getMaximumConsecutive(int[] coins) {
        int maxVal = 0;
        Arrays.sort(coins);
        for (int coin : coins) {
            if (coin > maxVal + 1) {
                break;
            }
            maxVal += coin;
        }
        return maxVal + 1;
    }
}
