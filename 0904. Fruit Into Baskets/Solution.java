import java.util.HashMap;
import java.util.Map;

class Solution {
    public int totalFruit(int[] fruits) {
        Map<Integer, Integer> counter = new HashMap<>();
        int i, j;
        for (i = 0, j = 0; j < fruits.length; j++) {
            counter.put(fruits[j], counter.getOrDefault(fruits[j], 0) + 1);
            if (counter.size() > 2) {
                counter.put(fruits[i], counter.get(fruits[i]) - 1);
                counter.remove(fruits[i++], 0);
            }
        }
        return j - i;
    }
}
