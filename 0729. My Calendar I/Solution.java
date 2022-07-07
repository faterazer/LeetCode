import java.util.Comparator;
import java.util.TreeSet;

class MyCalendar {
    private final TreeSet<int[]> booked = new TreeSet<>(Comparator.comparingInt(a -> a[0]));

    public MyCalendar() {

    }

    public boolean book(int start, int end) {
        int[] neighbour = booked.higher(new int[]{start, start});
        if (neighbour == null || neighbour[1] >= end) {
            booked.add(new int[]{end, start});
            return true;
        }
        return false;
    }
}

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar obj = new MyCalendar();
 * boolean param_1 = obj.book(start,end);
 */
