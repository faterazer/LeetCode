import java.util.*;

class Solution {
    public boolean canReorderDoubled(int[] arr) {
        Map<Integer, Integer> counter = new TreeMap<>();
        for (int e : arr) {
            counter.put(e, counter.getOrDefault(e, 0) + 1);
        }
        for (Integer key : counter.keySet()) {
            if (counter.get(key) == 0) {
                continue;
            }
            int want = key < 0 ? key / 2 : key * 2;
            if ((key < 0 && key % 2 != 0) || counter.getOrDefault(want, 0) < counter.get(key)) {
                return false;
            }
            counter.put(want, counter.get(want) - counter.get(key));
        }
        return true;
    }
}
