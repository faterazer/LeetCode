import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Set;

class Solution {
    public boolean uniqueOccurrences(int[] arr) {
        Map<Integer, Integer> map = new HashMap<>();
        for (int n : arr)
            map.put(n, map.getOrDefault(n, 0) + 1);
        Set<Integer> set = new HashSet<>();
        for (int occurrences : map.values()) {
            if (set.contains(occurrences))
                return false;
            set.add(occurrences);
        }
        return true;
    }
}
