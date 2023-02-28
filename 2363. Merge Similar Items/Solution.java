import java.util.*;

class Solution {
    public List<List<Integer>> mergeSimilarItems(int[][] items1, int[][] items2) {
        Map<Integer, Integer> map = new TreeMap<>();
        for (int[] v : items1) {
            map.put(v[0], map.getOrDefault(v[0], 0) + v[1]);
        }
        for (int[] v : items2) {
            map.put(v[0], map.getOrDefault(v[0], 0) + v[1]);
        }
        List<List<Integer>> res = new ArrayList<>();
        for (Map.Entry<Integer, Integer> entry : map.entrySet()) {
            res.add(Arrays.asList(entry.getKey(), entry.getValue()));
        }
        return res;
    }
}
