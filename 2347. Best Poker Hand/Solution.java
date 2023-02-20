import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Set;

class Solution {
    public String bestHand(int[] ranks, char[] suits) {
        Set<Character> set = new HashSet<>();
        for (char suit : suits) {
            set.add(suit);
        }
        if (set.size() == 1) {
            return "Flush";
        }
        Map<Integer, Integer> counter = new HashMap<>();
        for (int rank : ranks) {
            counter.put(rank, counter.getOrDefault(rank, 0) + 1);
        }
        if (counter.size() == 5) {
            return "High Card";
        }
        for (Integer value : counter.values()) {
            if (value > 2) {
                return "Three of a Kind";
            }
        }
        return "Pair";
    }
}
