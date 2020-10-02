import java.util.LinkedList;
import java.util.Queue;

class RecentCounter {
    private Queue<Integer> queue = new LinkedList<>();

    public RecentCounter() {

    }

    public int ping(int t) {
        queue.offer(t);
        while (t - queue.element() > 3000)
            queue.poll();
        return queue.size();
    }
}

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter obj = new RecentCounter();
 * int param_1 = obj.ping(t);
 */
