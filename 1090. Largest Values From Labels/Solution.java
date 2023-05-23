import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;
import java.util.stream.IntStream;

class Solution {
    public int largestValsFromLabels(int[] values, int[] labels, int numWanted, int useLimit) {
        int n = values.length;
        Integer[] indices = IntStream.range(0, n).boxed().toArray(Integer[]::new);
        Arrays.sort(indices, (a, b) -> values[b] - values[a]);

        Map<Integer, Integer> counter = new HashMap<>();
        int res = 0, count = 0;
        for (int i = 0; i < n && count < numWanted; i++) {
            int label = labels[indices[i]];
            counter.merge(label, 1, Integer::sum);
            if (counter.get(label) > useLimit) {
                continue;
            }
            res += values[indices[i]];
            ++count;
        }
        return res;
    }
}
