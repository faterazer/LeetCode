import java.util.HashMap;
import java.util.Map;
import java.util.Set;
import java.util.TreeSet;

class Solution {
    public int[] arrayRankTransform(int[] arr) {
        Set<Integer> set = new TreeSet<>();
        for (int x : arr) {
            set.add(x);
        }
        Map<Integer, Integer> map = new HashMap<>();
        for (Integer x : set) {
            map.put(x, map.size() + 1);
        }
        int[] res = new int[arr.length];
        for (int i = 0; i < arr.length; i++) {
            res[i] = map.get(arr[i]);
        }
        return res;
    }
}
