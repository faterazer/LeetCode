import java.util.Arrays;
import java.util.OptionalInt;

class Solution {
    public long minimumTime(int[] time, int totalTrips) {
        OptionalInt min = Arrays.stream(time).min();
        assert min.isPresent();
        long left = min.getAsInt(), right = left * totalTrips;
        while (left < right) {
            long mid = left + ((right - left) >> 1);
            long trips = 0;
            for (int t : time) {
                trips += mid / t;
            }
            if (trips < totalTrips) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return left;
    }
}
