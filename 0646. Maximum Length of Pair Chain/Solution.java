import java.util.Arrays;
import java.util.Comparator;

class Solution {
    public int findLongestChain(int[][] pairs) {
        Arrays.sort(pairs, Comparator.comparingInt(x -> x[1]));
        int last = Integer.MIN_VALUE, res = 0;
        for (int[] pair : pairs) {
            if (pair[0] > last) {
                last = pair[1];
                ++res;
            }
        }
        return res;
    }
}
