import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;

class Solution {
    public int numFactoredBinaryTrees(int[] arr) {
        int P = 1000000007;
        Arrays.sort(arr);

        Map<Integer, Long> counter = new HashMap<>();
        for (int e : arr) {
            counter.put(e, 1L);
        }
        for (int i = 1; i < arr.length; i++) {
            for (int j = 0; j < i; ++j) {
                if (arr[i] % arr[j] == 0) {
                    int a = arr[j], b = arr[i] / arr[j];
                    if (counter.containsKey(b)) {
                        counter.put(arr[i], (counter.get(arr[i]) + counter.get(a) * counter.get(b)) % P);
                    }
                }
            }
        }

        long res = 0L;
        for (Long e : counter.values()) {
            res = (res + e) % P;
        }
        return (int) res;
    }
}
