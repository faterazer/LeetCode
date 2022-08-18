import java.util.*;

class Solution {
    public int minSetSize(int[] arr) {
        Map<Integer, Integer> counter = new HashMap<>();
        for (int x : arr) {
            counter.put(x, counter.getOrDefault(x, 0) + 1);
        }
        List<Integer> buff = new ArrayList<>(counter.values());
        buff.sort(Collections.reverseOrder());
        int res = 0, len = arr.length, half = len / 2;
        for (Integer freq : buff) {
            len -= freq;
            ++res;
            if (len <= half) {
                break;
            }
        }
        return res;
    }
}
