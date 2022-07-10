import java.util.HashMap;
import java.util.Map;

class Solution {
    public int lenLongestFibSubseq(int[] arr) {
        Map<Integer, Integer> indices = new HashMap<>();
        for (int i = 0; i < arr.length; i++) {
            indices.put(arr[i], i);
        }
        int res = 0;
        Map<Integer, Integer> dp = new HashMap<>();
        for (int i = 0; i < arr.length; i++) {
            for (int j = 0; j < i; j++) {
                int need = arr[i] - arr[j];
                if (need > arr[j] && indices.containsKey(need)) {
                    int k = indices.get(need);
                    dp.put(k * 1000 + i, dp.getOrDefault(j * 1000 + k, 0) + 1);
                    res = Math.max(res, dp.get(k * 1000 + i) + 2);
                }
            }
        }
        return res > 2 ? res : 0;
    }
}
