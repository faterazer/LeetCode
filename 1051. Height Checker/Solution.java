import java.util.Arrays;

class Solution {
    public int heightChecker(int[] heights) {
        int[] buff = heights.clone();
        Arrays.sort(buff);
        int res = 0;
        for (int i = 0; i < heights.length; i++) {
            if (heights[i] != buff[i]) {
                res++;
            }
        }
        return res;
    }
}
