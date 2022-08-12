import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

class Solution {
    public List<List<Integer>> groupThePeople(int[] groupSizes) {
        List<List<Integer>> res = new ArrayList<>();
        Map<Integer, List<Integer>> groups = new HashMap<>();
        for (int i = 0; i < groupSizes.length; i++) {
            List<Integer> group = groups.computeIfAbsent(groupSizes[i], key -> new ArrayList<>());
            group.add(i);
            if (group.size() == groupSizes[i]) {
                res.add(group);
                groups.put(groupSizes[i], new ArrayList<>());
            }
        }
        return res;
    }
}
