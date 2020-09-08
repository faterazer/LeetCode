import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

class Solution {
    public String[] findRestaurant(String[] list1, String[] list2) {
        if (list1.length > list2.length)
            return findRestaurant(list2, list1);

        Map<String, Integer> index = new HashMap<>();
        for (int i = 0; i < list1.length; i++)
            index.put(list1[i], i);
        int minSum = Integer.MAX_VALUE;
        List<String> ret = new ArrayList<>();
        for (int i = 0; i < list2.length; i++) {
            String restaurant = list2[i];
            if (!index.containsKey(restaurant))
                continue;
            int sum = index.get(restaurant) + i;
            if (sum == minSum)
                ret.add(restaurant);
            else if (sum < minSum) {
                ret.clear();
                ret.add(restaurant);
                minSum = sum;
            }
        }
        return ret.toArray(new String[ret.size()]);
    }
}
