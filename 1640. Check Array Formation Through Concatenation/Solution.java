import java.util.HashMap;
import java.util.Map;

class Solution {
    public boolean canFormArray(int[] arr, int[][] pieces) {
        Map<Integer, Integer> n2p = new HashMap<>();
        for (int i = 0; i < pieces.length; i++) {
            n2p.put(pieces[i][0], i);
        }
        for (int i = 0; i < arr.length;) {
            if (!n2p.containsKey(arr[i]))
                return false;
            int[] p = pieces[n2p.get(arr[i])];
            for (int k : p)
                if (arr[i++] != k)
                    return false;
        }
        return true;
    }
}
