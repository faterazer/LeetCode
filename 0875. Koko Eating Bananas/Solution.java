import java.util.Arrays;

class Solution {
    public int minEatingSpeed(int[] piles, int h) {
        int left = 1, right = Arrays.stream(piles).max().orElse(1);
        while (left <= right) {
            int mid = left + ((right - left) >> 1);
            int hours = 0;
            for (int pile : piles) {
                hours += 1 + (pile - 1) / mid;
            }
            if (hours > h) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return left;
    }
}
