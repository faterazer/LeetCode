import java.util.Arrays;
import java.util.stream.IntStream;

class Solution {
    public int[] getConcatenation(int[] nums) {
        return IntStream.concat(Arrays.stream(nums), Arrays.stream(nums)).toArray();
    }
}
