import java.util.HashMap;
import java.util.Map;

class Solution {
    private static final Map<String, Integer> map = new HashMap<>();

    Solution() {
        map.put("Jan", 1);
        map.put("Feb", 2);
        map.put("Mar", 3);
        map.put("Apr", 4);
        map.put("May", 5);
        map.put("Jun", 6);
        map.put("Jul", 7);
        map.put("Aug", 8);
        map.put("Sep", 9);
        map.put("Oct", 10);
        map.put("Nov", 11);
        map.put("Dec", 12);
    }

    public String reformatDate(String date) {
        String[] ymd = date.split("\\s+");
        int year = Integer.parseInt(ymd[2]);
        int month = map.get(ymd[1]);
        int day = Integer.parseInt(ymd[0].substring(0, ymd[0].length() - 2));
        return String.format("%d-%02d-%02d", year, month, day);
    }
}
