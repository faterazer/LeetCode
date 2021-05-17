import java.util.Arrays;

class Solution {
    public int countBalls(int lowLimit, int highLimit) {
        int[] count = new int[46];
        for (int i = lowLimit; i <= highLimit; i++) {
            int digsum = 0;
            for (int j = i; j != 0; j /= 10) {
                digsum += j % 10;
            }
            count[digsum]++;
        }
        return Arrays.stream(count).max().getAsInt();
    }
}
