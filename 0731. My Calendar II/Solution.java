import java.util.HashMap;
import java.util.Map;

class MyCalendarTwo {
    private final Map<Integer, int[]> tree = new HashMap<>();

    public MyCalendarTwo() {

    }

    private void update(int start, int end, int idx, int left, int right, int val) {
        tree.computeIfAbsent(idx, e -> new int[]{0, 0});
        if (end < left || right < start) {
            return;
        }

        if (start <= left && right <= end) {
            tree.get(idx)[0] += val;
            tree.get(idx)[1] += val;
        } else {
            int mid = left + ((right - left) >> 1);
            update(start, end, idx * 2, left, mid, val);
            update(start, end, idx * 2 + 1, mid + 1, right, val);
            tree.get(idx)[0] = tree.get(idx)[1] + Math.max(tree.get(idx * 2)[0], tree.get(idx * 2 + 1)[0]);
        }
    }

    public boolean book(int start, int end) {
        update(start, end - 1, 1, 0, 1000000000, 1);
        if (tree.get(1)[0] > 2) {
            update(start, end - 1, 1, 0, 1000000000, -1);
            return false;
        }
        return true;
    }
}

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo obj = new MyCalendarTwo();
 * boolean param_1 = obj.book(start,end);
 */
 