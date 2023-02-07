import java.util.*;

class Solution {
    private int minutesOfDay(String time) {
        int hour = Integer.parseInt(time.substring(0, 2));
        int minute = Integer.parseInt(time.substring(3));
        return hour * 60 + minute;
    }

    public List<String> alertNames(String[] keyName, String[] keyTime) {
        Map<String, List<Integer>> map = new HashMap<>();
        for (int i = 0; i < keyName.length; i++) {
            String name = keyName[i], time = keyTime[i];
            map.computeIfAbsent(name, e -> new ArrayList<>()).add(minutesOfDay(time));
        }

        List<String> res = new ArrayList<>();
        for (Map.Entry<String, List<Integer>> entry : map.entrySet()) {
            String name = entry.getKey();
            List<Integer> records = entry.getValue();
            Collections.sort(records);
            for (int i = 2; i < records.size(); i++) {
                if (records.get(i) - records.get(i - 2) <= 60) {
                    res.add(name);
                    break;
                }
            }
        }
        Collections.sort(res);
        return res;
    }
}
