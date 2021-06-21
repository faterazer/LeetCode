import java.util.ArrayList;
import java.util.List;

class Solution {
    public List<String> readBinaryWatch(int turnedOn) {
        List<String> res = new ArrayList<>();
        for (int hour = 0; hour < 12; hour++) {
            for (int minute = 0; minute < 60; minute++) {
                if (Integer.bitCount(hour) + Integer.bitCount(minute) == turnedOn) {
                    res.add(String.format("%d:%02d", hour, minute));
                }
            }
        }
        return res;
    }
}
