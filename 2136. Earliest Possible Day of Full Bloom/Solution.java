import java.util.Arrays;
import java.util.Comparator;
import java.util.stream.IntStream;

class Solution {
    public int earliestFullBloom_MK1(int[] plantTime, int[] growTime) {
        Integer[] indices = IntStream.range(0, plantTime.length).boxed().toArray(Integer[]::new);
        Arrays.sort(indices, Comparator.comparingInt(i -> growTime[i]));
        int res = 0;
        for (Integer i : indices) {
            res = Math.max(res, growTime[i]);
            res += plantTime[i];
        }
        return res;
    }

    public int earliestFullBloom_MK2(int[] plantTime, int[] growTime) {
        Integer[] indices = IntStream.range(0, plantTime.length).boxed().toArray(Integer[]::new);
        Arrays.sort(indices, (i, j) -> growTime[j] - growTime[i]);
        int res = 0, endTime = 0;
        for (Integer i : indices) {
            endTime += plantTime[i];
            res = Math.max(res, endTime + growTime[i]);
        }
        return res;
    }
}
