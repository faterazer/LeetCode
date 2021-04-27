import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;

class Solution {
    public int[] frequencySort(int[] nums) {
        Map<Integer, Integer> counter = new HashMap<>();
        Arrays.stream(nums).forEach(n -> counter.put(n, counter.getOrDefault(n, 0) + 1));
        return Arrays.stream(nums).boxed().sorted((a, b) -> counter.get(a) != counter.get(b) ? counter.get(a) - counter.get(b) : b - a).mapToInt(n -> n).toArray();
    }
}
